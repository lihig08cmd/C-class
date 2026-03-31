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
  char value;

 public:
  Node(char v);
  ~Node();
  Node* getRight();
  Node* getLeft();
  Node* getNext();
  char getValue();
  void setRight(Node* r);
  void setLeft(Node* l);
  void setNext(Node* n);
  void setValue(char v);



};
#endif
