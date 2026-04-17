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
void addFile(Node*& root);
bool search(Node* root, int num);
Node* removeNum(Node* root, int num);
void print(Node* root, int space);
Node* findSmallest(Node* root);

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
      root = addNum(root, num);
    }
    else if(strcmp(command, "FILE") ==0){
      addFile(root);
    }
    else if(strcmp(command, "REMOVE") ==0){
      int num;
      cout << "Enter number to remvoe: " << endl;
      cin >> num;

      root = removeNum(root, num);
      //remove(root);
    }
    else if(strcmp(command, "SEARCH")==0){
      int num;
      cout << "Enter number to search in tree: " << endl;
      cin >>num;
      
      //cout << search(root, num) << endl;
      if(search(root, num)){
	cout << "This number was found in the tree" << endl;
      }
      else {
	cout << "This number was NOT found in tree" << endl;
      }
    }
    else if(strcmp(command, "PRINT") ==0){
      //cout << "else if P " << endl;
      //cout << root << endl;
      print(root, 0);
    }
    else if(strcmp(command, "QUIT")==0){
      cout << "BYE" << endl;
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


void addFile(Node*& root){
  // ask the user for the name file
  char filename[80];
  cout << "Enter file name: " << endl;
  cin >> filename;
  //open it
  ifstream file(filename);

  int num;
  while(file >> num){
    root = addNum(root, num);
  }
  
  //close file
  file.close();
}

bool search(Node* root, int num){
  if(root == NULL){
    return false;
  }

  // found
  if(root->value == num){
    return true;
  }

  // search right if num is larger
  if(root->value < num){
    return search(root->right, num);
  }
  // search left if num is smaller
  else {
    return search(root->left, num);
  }
  
}

Node* findSmallest(Node* root){
  // finding the smallset number in a subtree
  // so keep going left until null
  while(root->left != NULL){
    root = root->left;
  }
  return root;
}

Node* removeNum(Node* root, int num){
  //if the tree is empty
  if(root == NULL){
    return NULL;
  }

  // find the num in tree to delete
  // if num is smaller then go left
  if(num < root->value){
    root->left = removeNum(root->left, num);
  }
  //if num larger then go right
  else if(num > root->value){
    root->right = removeNum(root->right, num);
  }
  // else (found the node to delete)
  else{
    // Case 1: No children
    if(root->left == NULL && root->right ==NULL){
      // just delete it
      delete root;
      return NULL;
    }

    // case 2: has only right child
    else if(root->left == NULL){
      //replace node with right child
      Node* temp = root->right;
      delete root;
      return temp;
    }

    // case 3: has only left child
    else if(root->right == NULL){
      // replace node with left child
      Node* temp = root->left;
      delete root;
      return temp;
    }

    //case 4: has 2 children
    else {
      // delete by using successor. 
      Node* successor = findSmallest(root->right);
      // root value is now successor value (which is the next largest)
      root->value = successor->value;
      root->right = removeNum(root->right, successor->value);
    }
  }
  return root;
  
}

void print(Node* root, int space){
  //cout <<"in print function " << endl;

  if(root == NULL){
    return;
  }

  // print right side first (it will be at the top when it is printed)
  print(root->right, space+1);

  //print 
  for(int i=0; i<space; i++){
    cout << "   ";
  }
  cout << root->value << endl;

  //print left side (it will be at the bottom)
  print(root->left, space+1);
}
