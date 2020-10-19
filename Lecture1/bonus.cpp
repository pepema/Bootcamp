#include <iostream>
using namespace std;

int askQuestion(int index){
  int bit_value;
  cout << "From right, is the number " << index << " bit of your number 1? (y/n)" << endl;
  string ans;
  cin >> ans;
  if(ans == "y"){
    bit_value = 1;
  }
  else{
    bit_value = 0;
  }
  return bit_value << index;
}

int main(){

  cout << "Think of a number between 1 and 128 and i will guess it" << endl;
 
  int ans = 0;
  int correct_number = 0;
  for(int i = 0; i<7; i++){
    ans = askQuestion(i);
    correct_number += ans;
  }
  if(correct_number == 0){
    correct_number = 128;
  }

  cout << "Was this your number? " << correct_number << " (y/n)" << endl;
  string answer;
  cin >> answer;
  if(answer=="y"){
    cout << "Great success" << endl;
  }
  else{
    cout << "You're lying..." << endl;
  }
}