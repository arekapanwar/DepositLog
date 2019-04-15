//Areka Panwar


#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

struct PERSON{
    string Name;
    float Balance;};

void Display(PERSON *  a , int N) {
  cout << fixed << setprecision(2);
  

  cout <<setw(20)<< "Name" << setw(20)<<"Balance\n";
  cout << "----------------------------------------\n";

  for (int i = 0; i < N; i++) {
    cout <<setw(20) << a[i].Name << setw(20) << a[i].Balance << "\n";
  }
}

PERSON* readData(int & N) {
 
  string first_name;
  string last_name;
  string full_name;
  float salary;
  PERSON *Parray = new PERSON[N];
  ifstream inFile;
  inFile.open("data.txt");
  int i = 0;
  while (inFile && i < N){
  
    inFile >> first_name >> last_name >> Parray[i].Balance;
    full_name = first_name + " " + last_name;

   
    Parray[i].Name  = full_name;
     
    
    
    i++;
  }

  inFile.close();
  
  return Parray;

}

int CountData(){
  ifstream inFile;
  inFile.open("data.txt");
  int count = 0;
  string fname,lname;
  float salary;
  
  while (inFile){
    inFile >> fname >> lname >> salary;
    inFile.ignore(256, '\n');
    
    count++;
  }
  inFile.close();
  return count;
}

void FindRichest(PERSON * a, int & N){
  int max;
  string name;
  for (int i = 0; i < N; i++) {
    if (a[i].Balance > a[i+1].Balance){
      max = a[i].Balance;
      name = a[i].Name;
    }
  }
  cout << "Highest Balance: " << name << endl;
}

void Deposit (PERSON *& a, int & N) {
  string name;
  float dep;
  float bal;
  
  cout << "Enter name: ";
  getline(cin, name, '\n');  
  

  
  cout << "Amount: ";
  cin >> dep;

  

  for (int i = 0; i < N; i++) {
    if (a[i].Name == name) {
      a[i].Balance += dep;
      bal = a[i].Balance;
    }
  }
  cout << "New balance: " << bal << endl;
}

void UpdateRecords(PERSON *a, int & N) {
  ofstream outFile;
  outFile.open("data.txt");
  for(int i =0; i < N; i++) {
    outFile << a[i].Name << " " << a[i].Balance << endl;
  }
  outFile.close();
}
  

void printmenu() {
    cout << "Please enter a choice:" << endl;
    cout << "1. Display records"<< endl;
    cout << "2. Deposit funds"<< endl;
    cout << "3. Find Highest Balance" << endl;
    cout << "4. Update records" << endl;
    cout << "5. Exit the program" << endl;
}

int main()
{
   int number = CountData();

  PERSON * arryptr = readData(number);
 
  
    int choice;
    do
    {
        printmenu();
        cin >> choice;
        switch(choice)
        {
            case 1:Display(arryptr, number);
                // Act on display
                break;

	    case 2:Deposit(arryptr, number);
                // Act on deposit

                break;
	    case 3:FindRichest(arryptr, number);  // Act highest balance
                break;

	case 4:UpdateRecords(arryptr, number);
                // Act on update records
                break;

	case 5:UpdateRecords(arryptr, number);
                // Must call update records here before exiting the program
                break;

            default:
                cout << "Invalid entry" << endl;
                break;
        }
        cout << endl;
   } while(choice != 5);
    delete[] arryptr;
      return 0;
}
