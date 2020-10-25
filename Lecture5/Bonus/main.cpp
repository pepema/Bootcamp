#include "word_counter.hpp"

int main (){
  std::string one = "1.txt";
  std::string two = "2.txt";
  std::pair<std::string,std::string> input_files = {one,two};
  WordCounter *wc = new WordCounter(input_files);
  wc->CountWords();
  wc->PrintWords();
  wc->PrintWordsToFile();
  delete wc;
}