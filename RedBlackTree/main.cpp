// this is main
#include "redBlackTree.h"
#include <fstream>
#include <iostream>
using namespace std;

int main(){
  redBlackTree tree;
  
  char command[80];
  //cout << "Enter command(ADD, FILE, PRINT): " << endl;
  //cin>>command;

  while(true){
    //char command[80];
    cout << "Enter command(ADD, FILE, PRINT, SEARCH, DELETE, QUIT): " << endl;
    cin>>command;
    
    if(strcmp(command, "ADD") ==0){
      int num;
      cout<< "Enter number between 1 and 999: " << endl;
      cin>>num;
      tree.add(num);
    }
    else if(strcmp(command, "FILE")==0){
      char fileName[100];
      cout << "Enter file name: " << endl;
      cin >> fileName;
      tree.readFile(fileName);
    }
    else if(strcmp(command, "PRINT") ==0){
      tree.print();
    }
    else if(strcmp(command, "SEARCH")==0){
      int num;
      cout << "Enter a number to search" << endl;
      cin >>num;
      tree.search(num);
    }
    else if(strcmp(command, "DELETE")==0){
      int num;
      cout << "Enter number to delete: "<< endl;
      cin >>num;

      //tree.remove(num);
    }
    else if(strcmp(command, "QUIT") ==0){
      break;
    }
  }
  return 0;
}
