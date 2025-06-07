/*
ID = 24006910
Name = Aliya Maisarah
*/

#include <iostream>
#include <vector>
using namespace std;

struct Student {
      int ID;
      string name;
      string contact;
      string email;
    };

int main() 
{
    int n = 0;
    cout << "Enter number of students: ";
    cin >> n;
    
    vector<Student> students(n);
    
    for (int i=0; i<n; i++){
        cout << "Student " << i+1 << ": " << endl;
        cout << "Enter student ID: ";
        cin >> students[i].ID;
        cin.ignore();
        cout << "Enter student name: ";
        getline(cin, students[i].name);
        cout << "Enter student contact number: ";
        getline(cin, students[i].contact);
        cout << "Enter student email: ";
        getline(cin, students[i].email);
    }
    
    cout << "************List Of Students************" <<endl;
    for (int i=0; i<n; i++){
        cout << endl;
        cout << "Student " << i+1 << ": " << endl;
        cout << "ID: "<<students[i].ID <<endl;
        cout << "Name: "<<students[i].name<<endl;
        cout << "Contact: "<<students[i].contact<<endl;
        cout << "Email: "<<students[i].email<<endl;
        cout << "__________________________________________"<<endl;
    }
}