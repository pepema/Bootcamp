#include<iostream>
#include<array>
#include<algorithm>

void GenerateAndStore(std::array<std::pair<int,int>,34> &a){
  //create indexing
  for(int i=0;i<34;i++){
    a[i].first = i;
    a[i].second = 0;
  }
  //store random numbers
  for(int i=0;i<10000;i++){
    int r = rand()%34;
    a[r].second ++;
  }
}
void PrintArray(const std::array<std::pair<int,int>,34> &a){
  for(int i=0;i<34;i++){
    std::cout << "The number \"" << a[i].first << "\" was generated " << a[i].second << " times" << std::endl;
  }
}
bool CustomCompare(const std::pair<int,int> &p1, const std::pair<int,int> &p2){
  return p1.second < p2.second;
}
int main(){
  std::array<std::pair<int,int>,34> numbers;
  GenerateAndStore(numbers);
  std::sort(numbers.begin(),numbers.end(),CustomCompare);
  PrintArray(numbers);
}