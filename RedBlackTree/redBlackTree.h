// this is redBlackTree .h

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <iostream>
#include <cstring>
using namespace std;

struct Node{
  Node* left;
  Node* right;
  int value;
  // color
  Node* parent;
  
};

class redBlackTree{
 private:
  Node* root;

 public:
  redBlackTree();
  ~redBlackTree();

};
#endif
