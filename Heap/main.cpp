// Heap

#include <iostream>
#include <cstring>
using namespace std;

// functions prototypes
void add_num(int heap[101], num);
void add_file(int heap[101]);
void remove(int heap[101]);
void print(int heap[101]);


int main(){
  int heap[101];

  while(true){
    char command;
    cout << "Enter command(To add-NUMBERS/FILE, REMOVE, DISPLAY)"<< endl;
    cin>>command;
    //cin.getline(command,80);

    if(strcmp(command, "NUMBERS")==0){
      int num;
      cout << "Enter numbers: " << endl;
      cin>> num;
    }
    else if(strcmp(command, "FILE")==0){
      cout <<"add_file();" << endl;
    }
    else if(strcmp(command, "REMOVE")==0){
      cout <<"remove();   " << endl;
    }
    else if(strcmp(command,"DISPLAY")==0){
      cout <<"print();  " << endl;
    }
    return;
  }




}
