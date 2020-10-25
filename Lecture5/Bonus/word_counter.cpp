#include "word_counter.hpp"

WordCounter::WordCounter(std::pair<std::string,std::string> path_to_files){
  this->word_string = "";
  this->ReadFile(path_to_files.first);
  this->word_string += " ";
  this->ReadFile(path_to_files.second);
  this->path_to_output = path_to_files.second;
}

void WordCounter::ReadFile(std::string path){
  std::fstream input;
  std::string string;

  input.open(path,std::istringstream::in);
  if (!input.is_open()) {
    std::cout << "\"" <<path << "\"" << " could not be found" << std::endl;
  }   
  std::streampos index = input.tellg();
  input.seekg(0,std::ios::end);
  std::streampos size = input.tellg() - index;
  input.seekg(index);
  char *restOfTheFile = new char[size];
  input.read(restOfTheFile,size);
  this->word_string += this->ConvertToString(restOfTheFile,size);
  input.close();
  delete [] restOfTheFile;
}
std::string WordCounter::ConvertToString(char* a, int size){ 
    std::string s = ""; 
    for (int i = 0; i < size; i++) { 
        //replace newlines with space
        if(a[i]==10){
          s = s + " ";
        }
        //Only add lower case letters
        if( a[i] > 96 && a[i] < 123 ){
          s = s + a[i];
        //Otherwise add space if not already at back
        } else if( s.back() != 10 ){
          s = s + " ";
        }
    } 
    return s;
} 
void WordCounter::ConvertToLower(std::string &s){
  std::transform(s.begin(), s.end(), s.begin(),
    [](unsigned char c){ return std::tolower(c); });
}

void WordCounter::CountWords(){
  std::istringstream iss(this->word_string);
  auto str = std::string{};
  while (iss >> str) {
    this->ConvertToLower(str);
    it = words.find(str);
    if(it!=words.end()){
      words.at(str)++;
    }
    else{
      words.insert(std::pair<std::string,int>(str,1));
    }
  }
}

void WordCounter::PrintWords(){
  for(auto& x: words){
    std::cout << " [" << x.first << ':' << x.second << ']';
  }
  std::cout << '\n';
}

void WordCounter::PrintWordsToFile(){
  std::fstream output;
  output.open(this->path_to_output,std::fstream::out | std::fstream::app);
  output << '\n';
  for(auto& x:words){
    output << " [" << x.first << ':' << x.second << ']';
  }
  output << '\n';
  output.close();
}