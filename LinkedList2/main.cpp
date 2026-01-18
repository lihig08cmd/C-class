/* this is main.cpp

   Lihi Gavrielov
   1/  /26     */

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Node.h"
#include "Student.h"
using namespace std;

// function prototype
Node* createStudent();
Node* insertStudent(Node* current, Node* s);
void print(Node* current);
Node* deleteStudent(Node* current, int id);
int countNodes(Node* current);
float sumGPA(Node* current);

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
      Node* newStudent = createStudent();
      head = insertStudent(head,newStudent);
    }

    // if print
    else if (strcmp(input, "PRINT") ==0){
      print(head);
    }

    // if delete
    else if (strcmp(input, "DELETE")==0){
      cout << "delete" << endl;
      int deleteID;
      cout << "Enter student ID to delete: " << endl;
      cin >> deleteID;
      head = deleteStudent(head,deleteID);
    }

    // if avrege
    else if (strcmp(input, "AVERAGE") ==0){
      if(head == NULL){
	cout << "No students in list" << endl;
      }
      else{
	int count = countNodes(head);
	float sum = sumGPA(head);

	cout << "Average GPA: " << fixed << setprecision(2) << (sum/count) << endl;
      }
      
    }
    
    else if (strcmp(input, "QUIT")==0){
      break;
    }
  }
  return 0;
}

// add function
Node* createStudent(){
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

// insert a new node into your linked list, sorting it by student id number  
Node* insertStudent(Node* current, Node* s){
  //if current is NuLL or student ID # higher then the current ID #
  if(current == NULL || s->getStudent()->getID() < current->getStudent()->getID()){
    // set current pointer to students next pointer
    s->setNext(current);
    return s;
  }

  // more to the next node
  current->setNext(insertStudent(current->getNext(),s));
  return current;
}


// print function
void print(Node* current){
  if (current == NULL){
    return;
  }

  current->getStudent()->print();
  print(current->getNext());
  
}

// Prompt the user for the student id number to delete
Node* deleteStudent(Node* current, int id){
  if(current == NULL){
    return current;
  }

  if (current->getStudent()->getID() == id){
    Node* temp = current->getNext();
    delete current;
    return temp;
    
  }

  current->setNext(deleteStudent(current->getNext(), id));
  return current;
}

int countNodes(Node* current){
  if (current==NULL){
    return 0;
  }

  return 1 + countNodes(current->getNext());
}

float sumGPA(Node* current){

  if (current==NULL){
    return 0;
  }

  return current->getStudent()->getGPA() + sumGPA(current->getNext());
}


