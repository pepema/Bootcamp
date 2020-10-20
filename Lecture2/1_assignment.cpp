#include <iostream>
using namespace std;

int  main(){
  int recieved_number,rows,columns,instances;

  do {
    cout << "Please provide the following, space separated: " << endl;
    cout << "1. Postivive integer to generate random number below" << endl;
    cout << "2. Amount of columns of the table" << endl;
    cout << "3. Amount of rows of the table " << endl;
    cout << "4. Amount of instances of the table " << endl;
    cin >> recieved_number >> rows >> columns >> instances;
  }
  while(recieved_number<0||rows<0||columns<0||instances<0);

  int *** p_ = new int **[instances];
  for(int i=0;i<instances;i++){
    *(p_+i) = new int*[rows];
    for(int j=0;j<rows;j++){
      *(*(p_+i)+j) = new int[columns];
      for(int k=0;k<columns;k++){
        *(*(*(p_+i)+j)+k) = rand()%recieved_number;
        if(*(*(*(p_+i)+j)+k)<10){
          cout << *(*(*(p_+i)+j)+k) << "   ";
        }
        else if(*(*(*(p_+i)+j)+k) < 100){
          cout << *(*(*(p_+i)+j)+k) << "  ";
        }
        else if(*(*(*(p_+i)+j)+k) < 1000){
          cout << *(*(*(p_+i)+j)+k) << " ";
        }
        else{
          cout << *(*(*(p_+i)+j)+k) << "";
        }
      }
      cout << "" << endl;
    }
    cout << "" << endl;
  }
}