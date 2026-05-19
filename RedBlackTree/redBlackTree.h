// this is redBlackTree .h

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//each node must be either red or black
enum Color{RED, BLACK};

struct Node{
  Node* left;
  Node* right;
  int value;
  Color color;

  //points to the parent node above it (helps with fixing tree)
  Node* parent;

  //constractor
  Node(int data);
};

class redBlackTree{
 private:
  Node* root;

  //moves nodes LEFT to balance tree
  void rotateLeft(Node* current);
  // moves nodes RIGHT to balance tree
  void rotateRight(Node* current);
  
  void fixTree(Node* current);
  //print tree sideways 
  void print(Node* current, int space);

  // search healper
  Node* search(Node* current, int value);

  //for delete
  Node* findSuccessor(Node* current);

 public:
  redBlackTree();
  ~redBlackTree();

  void add(int data);
  void readFile(char fileName[]);
  //print from root
  void print();

  void search(int value);
  void remove(int value);

};
#endif
