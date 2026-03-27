// Heap

#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream> 
using namespace std;

// functions prototypes
void add_num(int heap[100],int last_idx, int num); //adds num to the heap in "last place
void add_file(int heap[100], int last_idx); //add numbers from file to heap 
void remove(int heap[100]);//
void print(int heap[100]);


int main(){
  int heap[100];
  int last_idx =0;  

  while(true){
    char command;
    cout << "Enter command(To add-NUMBERS/FILE, REMOVE, DISPLAY, QUIT)"<< endl;
    cin>>command;
    //cin.getline(command,80);

    if(strcmp(command, "NUMBERS")==0){
      int num;
      cout << "Enter a number between 1 and 1000: " << endl;
      cin>> num;
      add_num(heap,last_idx,num);
    }
    else if(strcmp(command, "FILE")==0){
      add_file(int heap[100], int last_idx);
    }
    else if(strcmp(command, "REMOVE")==0){
      cout <<"remove();   " << endl;
    }
    else if(strcmp(command,"DISPLAY")==0){
      cout <<"print();  " << endl;
    }
    else if(strcmp(command, "QUIT") ==0){
      break;
    }
  }
  return 0;
}

void add_num(int heap[100],int last_idx, int num){
  // checks if heap is full
  if(last_idx > 99){
    cout <<"Heap is full with 100 numbers" << endl;
    return;
  }

  heap[last_idx] = num;

  //swap if num is larger then parent num
  int parent_idx = (last-1)/2;
  while(heap[last_idx]>heap[parent_idx]){
    int temp = heap[last_idx];
    heap[last_idx]= heap[parent_idx];
    heap[parent_idx] = temp;
  }

}

void add_file(int heap[100], int last_idx){
  // ask user for file name then open it
  char filename[80];
  cout <<"Enter file name: " << endl;
  cin.getline(filename, 80);
  ifstream file(filename);
  
  add_num(heap,last_idx,num);




  // close file
  file.close();
}


