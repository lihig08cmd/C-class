/* this is main.cpp

   Lihi Gavrielov
   1/  /26     */

#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"
using namespace std;

// function prototypy
void addStudent();
void print(Node* n);
void deleteStudent(Node* n);


int main(){

  //head pointer
  Node* head = NULL;

  char input[80];

  while(true){

    // asks user
    cout << "Enter command (ADD, PRINT, DELETE, QUIT, AVERAGE: " << endl;
    cin >> input;

    // if add
    if (strcmp(input, "ADD") == 0){
      add();
    }

    // if print
    else if (strcmp(input, "PRINT") ==0){
      print(Node* n);
    }

    // if delete
    else if (strcmp(input, "DELETE")==0){
      int id;
      cout << "Enter ID to delete: " << endl;
      cin >> id;

      // remove the student
      
    }

    // if avrege
    else if (strmpy(input, "AVERAGE") ==0){
      int count = 0;
    }
    
    else if (strcmp(input, "QUIT")==0){
      break;
    }
  }
  return 0;
}

// add function
void addStudent(){
  char first[80];
  char last [80];
  int id;
  float gpa;

  // ask the user for the info
  cout << "Enter first name: " << endl;
  cin >> first;
  cout << "Enter last name: " << endl;
  cin >> last;
  cout << "Enter student ID: " << endl;
  cin >> id;
  cout << "Enter GPA: " << endl;
  cin >> gpa;

  // creat a new student
  Student* s = new Student(first, last, id, gpa);

  // creating node for
  Node* n = new Node(s);

  return n;
}

// print function
void print(Node* n){
  // check if these are students
  

  
}
