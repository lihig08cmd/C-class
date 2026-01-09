/*  This is the main class for linked lists

    Lihi Gavrielov
    12/18/25       */

#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"
using namespace std;

int main(){
  // create students
  Student* stu1 = new Student("Lihi", 495745);
  Student* stu2 = new Student("RL", 123456);
  // create Nodes
  Node* n1 = new Node(stu1);
  Node* n2 = new Node(stu2);

  //testing setNext
  
  n1->setNext(n2);

  // Texting getStudent
  cout << "testing getStudent. First: " << endl;
  n1->getStudent()->print();

  cout << "Second: " << endl;
  n1->getNext()->getStudent()->print();

  // testing getNext
  if(n1->getNext() != NULL){
    cout << "Next one exists." << endl;
  }

  delete stu1;
  delete stu2;
  delete n1;
  delete n2;

  return 0;
  
}
