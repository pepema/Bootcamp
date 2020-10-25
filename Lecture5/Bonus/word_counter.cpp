#include "word_counter.hpp"

WordCounter::WordCounter(std::pair<std::string,std::string> path_to_files){
  std::fstream input;
  input.open(path_to_files.first,std::istringstream::in);
  std::string string;

  std::streampos index = input.tellg();
  input.seekg(0,std::ios::end);
  std::streampos size = input.tellg() - index;
  input.seekg(index);
  char *restOfTheFile = new char[size];
  input.read(restOfTheFile,size);
  this->word_string = this->ConvertToString(restOfTheFile,size);
  delete [] restOfTheFile;
}

std::string WordCounter::ConvertToString(char* a, int size){ 
    int i; 
    std::string s = ""; 
    for (i = 0; i < size; i++) { 
        if(a[i]==10){
          //replace newlines with space
          s = s + " ";
        }
        else{
          s = s + a[i];
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
  for (auto& x: words)
    std::cout << " [" << x.first << ':' << x.second << ']';
  std::cout << '\n';
}