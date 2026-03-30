// this is node.h

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>
using namespace std;

class Node{
 private:
  Node* right;
  Node* left;
  Node* next;
  Node* prev;
  char value;

 public:
  Node();
  ~Node();
  Node* getRight();
  Node* getLeft();
  Node* getNext();
  Node* getPrev();
  char getValue();
  void setRight(Node* r);
  void setLeft(Node* l);
  void setNext(Node n);
  void setPrev(Node p);
  void setValue(char v);



};
#endif
