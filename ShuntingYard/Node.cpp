// this is node .cpp

#include <iostream>
#include <cstring>
#include "Node.h"
using namespace std;

Node::Node(char v){
  value = v;
  left = NULL;
  right = NULL;
  next = NULL;
}

Node::~Node(){  
}

Node* Node:: getRight(){
  return right;
}

Node* Node::getLeft(){
  return left;
}

Node* Node::getNext(){
  return next;
}

char Node::getValue(){
  return value;
}

void Node::setRight(Node* r){
  right=r;
}

void Node::setLeft(Node* l){
  left=l;
}

void Node::setNext(Node* n){
  next = n;
}

void Node::setValue(char v){
  value = v;
}

