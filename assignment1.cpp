#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

struct PERSON{
    char Name[20];
    float Balance;};

void Display(PERSON a[] , int N) {
  cout << fixed << setprecision(2);
  

  cout <<setw(20)<< "Name" << setw(20)<<"Balance\n";
  cout << "----------------------------------------\n";

  for (int i = 0; i < N; i++) {
    cout <<setw(20) << a[i].Name << setw(20) << a[i].Balance << "\n";
  }
}




int main() {

  string fName;
  string lName;
  string sName;
  float salary;
  
  

  
 

  PERSON P[6];

  char _name[20];
  ifstream inFile;
  inFile.open("data.txt");
  int i=0;
  int j = 0;

  while (inFile) {
    inFile >> fName >> lName >> salary;
    inFile.ignore(256, '\n');
    sName = fName + " " + lName;
    for (int j = 0; j < 20; j++) {
      _name[j] = sName[j];
	}
    strcpy(P[i].Name,_name);
    P[i++].Balance = salary;
    
  }

  
    
  Display(P, 6);

  inFile.close();


  return 0;

}
