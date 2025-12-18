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
  Student* stu1 = new Student();
  Student* stu2 = new Student();
  // create Nodes
  Node* n1 = new Node(stu1);
  Node* n2 = new Node(stu2);

  //testing setNext


  // Texting getStudent


  // testing getNext


  return 0;
  
}
