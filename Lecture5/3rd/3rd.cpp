#include<iostream>
#include<array>
#include<algorithm>

void FillArray(std::array<int,1024> &a){
  for(int i=0;i<1024;i++){
    a[i]=rand();
  }
}
void PrintArray(const std::array<int,1024> &a){
  for(int i=0;i<1024;i++){
    std::cout << a[i] << std::endl;
  }
}
std::pair<int,int> FindClosest(const std::array<int,1024> &a, int target){
  int size = 1023;
  std::pair<int,int> ret;
  if(target < a[0]){
    ret.first = 0;
    ret.second = a[0];
    return ret;
  }
  if(target > a[size]){
    ret.first = a[size];
    ret.second = INT32_MAX;
    return ret;
  }

  int mid, ret1, ret2, counter=0, i=0, j=size+1;
  while(i<j && counter<=12){
    mid = (i+j)/2;
    counter++;
    if (a[mid] == target){
      ret.first = a[mid-1];
      ret.second = a[mid+1];
      break;
    }
    if (target < a[mid]) { 
      if (mid > 0 && target > a[mid - 1]){
        ret.first = a[mid-1];
        ret.second = a[mid];
        break;
      } else{
        j = mid; 
      }
    } 
    else { 
      if (mid < 1023 && target < a[mid + 1]){
        ret.first = a[mid];
        ret.second = a[mid+1];
        break;
      }
      else{
        i = mid + 1;  
      }
    } 
  }
  std::cout << "this is the counter: " << counter << std::endl;
  return ret;
}
void PrintResult(std::pair<int,int> p, int r){
  if(p.first == 0){
    std::cout << "There was no smaller number"        << std::endl;
    std::cout << "The closest bigger number was: "    << p.second << std::endl;
  } else if (p.second == INT32_MAX){
      std::cout << "The closest smaller number was: " << p.first << std::endl;
      std::cout << "There was no bigger number"       << std::endl;
  } else {
      std::cout << "The closest smaller number was: " << p.first << std::endl;
      std::cout << "The closest bigger number was: "  << p.second << std::endl;
  }

  std::cout << "The random number was: "              << r << std::endl;
}
int main(){
  std::array<int,1024> random_numbers;
  FillArray(random_numbers);
  std::sort(random_numbers.begin(),random_numbers.end());
  PrintArray(random_numbers);
  int r = rand();

  //int r = 2113903881;
  //int r = INT32_MAX-2;
  
  std::pair<int,int> result = FindClosest(random_numbers,r);
  std::cout << "------------------------------" << std::endl;
  PrintResult(result,r);
}