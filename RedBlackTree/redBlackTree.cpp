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
void redBlackTree::rotateLeft(Node* current){
  //node on right is child
  Node* child = current->right;

  // current's right pointer is now whatever child's left side was
  current->right = child->left;

  // fix parent pointer
  if(child->left != NULL){
    child->left->parent = current;
  }

  //child moves up
  child->parent = current->parent;

  // if current was root then child becomes root
  if(current->parent == NULL){
    root = child;
  }
  // if current was left child of parent then parent's left now is child
  else if(current == current->parent->left){
    current->parent->left = child;
  }
  //if current was right child of parent then parent's right now is child
  else{
    current->parent->right = child;
  }

  //child's left now becomes current
  child->left = current;

  // current parent is now child
  current->parent = child;
}


//shift nodes Right
void redBlackTree::rotateRight(Node* current){
  //child is the node on left side
  Node* child = current->left;

  //current's left is now whatever child's right side was
  current->left = child->right;

  // if subtree exists fix parent
  if(child->right != NULL){
    child->right->parent = current;
  }

  //child move up
  child->parent = current->parent;

  //if current is root
  if(current->parent == NULL){
    root=child;
  }
  // if current was right child then parent right is now child
  else if(current == current->parent->right){
    current->parent->right = child;
  }
  //else. when current was right child then parent left is now child
  else{
    current->parent->left = child;
  }

  // child right is now current
  child->right = current;

  //current parent is now child
  current->parent = child;
}

//fixing the colors
void redBlackTree::fixTree(Node* current){
  // while current is not root AND parent is red
  while(current != root && current->parent != NULL &&current->parent->color == RED){
    Node* parent = current->parent;
    Node* grandparent = parent->parent;

    if(grandparent == NULL){
      break;
    }

    //parent is left child
    if(parent == grandparent->left){
      //uncle is opposite side
      Node* uncle = grandparent->right;

      // if uncle is red
      if(uncle != NULL && uncle->color == RED){
	//parent is now black
	parent->color = BLACK;

	// uncle is now black
	uncle->color = BLACK;

	//grandparent is now red
	grandparent->color = RED;

	//move up and keep checking
	current = grandparent;
      }
      else{
	//current is right child
	if(current == parent->right){
	  //move current up one
	  current = parent;

	  //rotate parent left
	  rotateLeft(current);
	}
	//parent is now black
	parent->color = BLACK;
	//grandparent is now red
	grandparent->color = RED;

	//rotate grandparent right
	rotateRight(grandparent);
      } 
    }
    // parent is right child
    else{
      Node* uncle = grandparent->left;

      if(uncle != NULL && uncle->color == RED){
	parent->color = BLACK;
	uncle->color = BLACK;
	grandparent->color = RED;

	current = grandparent;
      }
      else {
	//
	if(current == parent->left){
	  current = parent;

	  rotateRight(current);
	}
	parent->color = BLACK;
	grandparent->color = RED;

	rotateLeft(grandparent);
      }
    }
  }
  //root always black
  root->color = BLACK;
}

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
  if(parent == NULL){
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
  fixTree(newNode);
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

  //show parent
  if(current->parent != NULL){
    cout << "P:" << current->parent->value;
  }
  else{
    cout << "P:NULL";
  }

  cout << endl;

  //print left side (it will be at the bottom)
  print(current->left, space+1);

}

//print
void redBlackTree::print(){
  print(root, 0);
}

