// this is Node .h  //

#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node{
 private:
  // pointer to a student object
  Student* student;
  // pointer to next Node
  Node* next;


 public:
  //Constructor
  Node(Student* newStudent);

  //destructor
  ~Node();

  // get next Node pointer
  Node* getNext():

  //get student pointer
  Student* getStudent();

  //set the next Node pointer
  void setNext(Node* newNext);
};
#endif
