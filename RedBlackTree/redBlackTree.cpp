// this is redBlackTree .cpp
#include "redBlackTree.h"

//Node constructor
Node::Node(int data){
  left = NULL;
  right = NULL;
  parent = NULL;
  value = data;
  color = RED;
  
}

//Tree constractor
redBlackTree::redBlackTree(){
  root = NULL;
}

// destructor
redBlackTree::~redBlackTree(){
}

// shift nodes left
/*
void redBlackTree::rorateLeft(Node* current){

}

//shift nodes Right
void redBlackTree::rotateRight(Node* current){
  
}

void redBlackTree::fixTree(Node* current){

}

*/

// add node
void redBlackTree::add(int data){
  //making new node
  Node* newNode = new Node(data);

  Node* current = root;
  Node* parent = NULL;

  //find where now node supposed to be
  while(current != NULL){
    // save previous node
    parent = current;

    // if smaller left
    if(data < current->value){
      current = current->left;
    }
    // else. bigger or equal right
    else{
      current = current->right;
    }
  }

  // connect parent pointer
  newNode->parent = parent;

  //if tree empty new node becomes root
  if(parent = NULL){
    root = newNode;
  }

  //if smaller than parent then left parent is now the new node
  else if(data < parent->value){
    parent->left = newNode;
  }

  // if bigger than parent then right parent becomes new node
  else{
    parent->right = newNode;
  }

  // call fixtree so the tree will be balace and the right color

}

// read file
void redBlackTree::readFile(char fileName[]){
  ifstream file(fileName);

  int num;

  // read each num one by one
  while(file >> num){
    add(num);
  }
  file.close();
}

// print tree sideways
void redBlackTree::print(Node* current, int space){
  if(current == NULL){
    return;
  }

  // print right side first (it will be at the top when it is printed)
  print(current->right, space+1);

  //print 
  for(int i=0; i<space; i++){
    cout << "   ";
  }
  cout << current->value;

  //show color
  if(current->color == RED){
    cout <<"(R)";
  }
  else{
    cout <<"(B)";
  }

  cout << endl;

  //print left side (it will be at the bottom)
  print(current->left, space+1);

}

//print
void redBlackTree::print(){
  print(root, 0);
}

