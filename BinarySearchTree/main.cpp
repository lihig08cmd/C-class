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
void addNUm(Node* root, int num);
void addFile(Node* root);
void search(Node* root, int num, );
void remove(Node* root, int num);
void print(Node* root);

int main(){
  Node* root;
  
  while(true){
    char command[80];
    cout << "Enter command(To add-NUM/FILE, REMOVE, SEARCH, PRINT, QUIT):" << endl;
    cin >> command;

    if(strcmp(command, "NUMBERS") ==0){
      int num;
      cout << "Enter number between 1 and 999: " endl;
      cin>>num;
      addNum(root, num);
    }
    else if(strcmp(command, "FILE") ==0){
      addFile(root);
    }
    else if(strcmp(command, "REMOVE") ==0){
      remove(root);
    }
    else if(strcmp(command, "SEARCH")==0){
      search(root);
    }
    
  }


}

// add function

