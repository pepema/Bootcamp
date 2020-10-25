#include "word_counter.hpp"

int main(int argc, char** argv){
  if(argc<3){
    std::cout << "Too few arguments provided.." << std::endl;
    std::cout << "Expects two files as input arguments" << std::endl;
    return EXIT_FAILURE;
  }
  std::string one = argv[1];
  std::string two = argv[2];

  std::pair<std::string,std::string> input_files = {one,two};
  WordCounter *wc = new WordCounter(input_files);
  wc->CountWords();
  wc->PrintWords();
  wc->PrintWordsToFile();
  delete wc;
  return EXIT_SUCCESS;
}