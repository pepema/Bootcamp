#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <algorithm>

class WordCounter{
public:
  //void CountWords(std::string &s);
  void CountWords();
  void PrintWords();
  WordCounter() = default;
  WordCounter(std::pair<std::string,std::string> path_to_files);
  ~WordCounter() = default;
private:
  std::string word_string;
  std::map<std::string,int> words;
  std::map<std::string,int>::iterator it;
  void ConvertToLower(std::string &s);
  std::string ConvertToString(char* a, int size);
};