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

  int *** p_instaces;
  int ** p_rows;
  int * p_columns;
  p_instaces = new int **[instances];
  p_rows = new int*[rows];
  p_columns = new int[columns];

  for(int i=0;i<instances;i++){
    for(int j=0;j<rows;j++){
      for(int k=0;k<columns;k++){
        int random_number = rand()%recieved_number;
        p_columns[i] = random_number;
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