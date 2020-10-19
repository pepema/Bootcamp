#include <string>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string Decrypt(int key, string encrypted){
  int encrypted_length = encrypted.length();
  //Needed because string decrypted = "" always generates a length of 0
  string decrypted = encrypted;
  //decrypted.resize(encrypted_length);
  for(int i=0;i<encrypted_length;i++){
    if(encrypted[i]-key < 65){
      int offset = encrypted[i] - key + 26;
      decrypted[i] = offset;
    }
    else{
      decrypted[i] = encrypted[i]-key;
    }
    
    //debugging stuff.......
    /*
    cout << "this is i: " << i << " ";
    cout << "this is the decrypted value: " << decrypted[i] << " ";
    cout << "this is the encrypted value: " << encrypted[i] << endl;
    */
    //cout << decrypted.size();

  }
  //cout << decrypted.size();
  return decrypted;
}

int main(){
  string cipher;
  int key = 0;

  do {
    cout << "Please provide a key between 0 and 26" << endl;
    cin >> key;
  }
  while(key < 0 || key > 26);

  cout << "Please provider a cipher text" << endl;
  cin >> cipher;

  string decrypted = Decrypt(key,cipher);
  cout << decrypted << endl;
}