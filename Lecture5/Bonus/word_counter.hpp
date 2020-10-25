#ifndef WORD_COUNTER_HPP_
#define WORD_COUNTER_HPP_

#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <algorithm>

class WordCounter{
public:
  void CountWords();
  void PrintWords();
  void PrintWordsToFile();
  WordCounter() = default;
  WordCounter(std::pair<std::string,std::string> path_to_files);
  ~WordCounter() = default;
private:
  std::string word_string;
  std::string path_to_output;
  std::map<std::string,int> words;
  std::map<std::string,int>::iterator it;
  void ConvertToLower(std::string &s);
  std::string ConvertToString(char* a, int size);
  void ReadFile(std::string path);
};

#endif