#include <iostream>
using namespace std;

int  main(){
  int recieved_number;

  do {
    cout << "Please provide a posivitve integer" << endl;
    cin >> recieved_number;
  }
  while(recieved_number<0);
  int random_number_array[8][9][11];
  for(int i=0;i<8;i++){
    for(int j=0;j<9;j++){
      for(int k=0;k<11;k++){
        int random_number = rand()%recieved_number;
        random_number_array[i][j][k] = random_number;
        if(random_number<10){
          cout << random_number << "   ";
        }
        else if(random_number < 100){
          cout << random_number << "  ";
        }
        else if(random_number < 1000){
          cout << random_number << " ";
        }
        else{
          cout << random_number << "";
        }
      }
      cout << "" << endl;
    }
    cout << "" << endl;
  }

}