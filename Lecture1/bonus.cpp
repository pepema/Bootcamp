#include <iostream>
using namespace std;

int askQuestion(int index){
  int bit_value;
  cout << "Is the number " << index << " bit of your number 1? (y/n)";
  string ans;
  cin >> ans;
  if(ans == "y"){
    bit_value << index;
  }
  else{
    bit_value << index;
  }
  cout << bit_value << endl;
  return bit_value;
}

int main(){

  cout << "Think of a number between 1 and 128 and i will guess it" << endl;
 
  int ans;
  int current_number;
  string correct_number;
  for(int i = 0; i<7; i++){
    ans = askQuestion(i);
  }
  cout << correct_number << endl;
  cout << "Was this your number? " << correct_number << " (y/n)" << endl;

  string answer;
  cin >> answer;

  if(answer=="y"){
    cout << "Great succes" << endl;
  }
  else{
    cout << "You're lying..." << endl;
  }
}