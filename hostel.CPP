#include <iostream>
#include<conio.h>
#include<string.h>
#include<fstream>
using namespace std;

class student
{
private:
  int roomno;
  char name[50];
  char address[100];
  char phone[10];

public:
  void input()
  {
    cout<<"enter roomno";
  cin>>roomno;
  cin.ignore();
  cout<<"enter student name";
  cin.getline(name,50);
  cout<<"enter address";
  cin.getline(address,100);
  cout<<"enter phone no";
  cin.getline(phone,10);
  }

  void show()
  {
  cout << "RollNo: " << roomno;
  cout << "Name: " << name;
  cout << "Address: " << address;
  cout << "Phone: " << phone<<endl;
   
}

  void savetofile()
{
  ofstream fout;
  fout.open("hostel.txt",ios::app);
  fout<<"roomno: "<<roomno<<endl;
  fout<<"name: "<<name<<endl;
  fout<<"address: "<<address<<endl;
  fout<<"phone: "<<phone<<endl;
  fout<<endl;
  fout.close();
}

bool loadfromfile(ifstream &fin)
{
  if(!(fin>>roomno))return false;
  fin.ignore();
 if (!fin.getline(name, 50)) return false;
    if (!fin.getline(address, 100)) return false;
    if (!fin.getline(phone, 10)) return false;
    fin.ignore(1000,'\n');
 return true;
}

int getroomno() 
  {
    return roomno;
  } 
};

//add student
void addstudent()
{
  student s;
  s.input();
  s.savetofile();
  cout<<"student added successfully";

}

//display all students
void displayall()
{
  ifstream fin;
  fin.open("hostel.txt");
  student s;
   if (!s.loadfromfile(fin)) {
        cout << "No records found.";
        return;
    }

    do {
        s.show();
        cout << "\n-----"<<endl;
    } while (s.loadfromfile(fin));

    fin.close();
}

//search by room no
void searchstudent()
{
  int room;
  cout<<"enter room no to search";
  cin>>room;
  ifstream fin;
  fin.open("hostel.txt");
  student s;
  while (s.loadfromfile(fin)) {
        if (s.getroomno() == room) {
            s.show();
            fin.close();
            return;
        }
    }

    fin.close();
    cout << "\nStudent not found.";
}

void menu()
{
  int choice;
  do{
    
   cout << "\n\n--- Hostel Management System ---";
        cout << "\n1. Add Student";
        cout << "\n2. Display All Students";
        cout << "\n3. Search Student by Room No";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: addstudent(); break;
        case 2: displayall(); break;
        case 3: searchstudent(); break;
        case 4: cout << "\nExiting..."; break;
        default: cout << "\nInvalid choice!";
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}




