// Binary Search tree
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

// nodes
struct Node{
  Node* left;
  Node* right;
  int value;
};

// function prototype
Node* addNum(Node* root, int num);
void addFile(Node* root);
bool search(Node* root, int num);
Node* remove(Node* root, int num);
void print(Node* root, int space);

int main(){
  Node* root = NULL;
  
  while(true){
    char command[80];
    cout << "Enter command(To add-NUM/FILE, REMOVE, SEARCH, PRINT, QUIT):" << endl;
    cin >> command;

    if(strcmp(command, "NUM") ==0){
      int num;
      cout << "Enter number between 1 and 999: " << endl;
      cin>>num;
      addNum(root, num);
    }
    else if(strcmp(command, "FILE") ==0){
      addFile(root);
    }
    else if(strcmp(command, "REMOVE") ==0){
      int num;
      cout << "Enter number to remvoe: " << endl;
      cin >> num;
      
      //remove(root);
    }
    else if(strcmp(command, "SEARCH")==0){
      //search(root);
    }
    else if(strcmp(command, "P") ==0){
      print(root, 0);
    }
    else if(strcmp(command, "QUIT")==0){
      break;
    }
  }
  return 0;
}

// add function
Node* addNum(Node* root, int num){
  // if empty
  if(root ==NULL){
    Node* newNode = new Node();
    newNode->value = num;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  }

  //go left if smaller
  if(num < root->value){
    root->left = addNum(root->left, num);
  }

  // go right if larger
  else if(num > root->value){
    root->right = addNum(root->right, num);
  }
  return root;
}


void addFile(Node* root){
  // ask the user for the name file
  char filename[80];
  cout << "Enter file name: " << endl;
  cin >> filename;
  //open it
  ifstream file(filename);

  int num;
  while(file >> num){
    addNum(root, num);
  }
  
  //close file
  file.close();
}

void print(Node* root, int space){
  if(root == NULL){
    return;
  }

  cout << "=============" << endl;

  
  print(root->right, space +1);

  //print
  for(int i=0; i<space; i++){
    cout << " ";
  }

  cout << root->value << endl;

  //print left side
  print(root->left, space+1);
}
