// Heap

#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream> 
using namespace std;

// functions prototypes
void add_num(int heap[101],int &last_idx, int num); //adds num to the heap in "last place
void add_file(int heap[101], int &last_idx); //add numbers from file to heap 
void remove(int heap[101]);//
void print(int heap[101], int last_idx);
void swap(int heap[101], int a, int b); // swaping 


int main(){
  int heap[101];
  int last_idx = 1;  

  while(true){
    char command[80];
    cout << "Enter command(To add-NUMBER/FILE, REMOVE, DISPLAY, QUIT)"<< endl;
    cin>>command;
    //cin.getline(command,80);

    if(strcmp(command, "NUMBER")==0){
      int num;
      cout << "Enter a number between 1 and 1000: " << endl;
      cin>> num;
      add_num(heap,last_idx,num);
      
    }
    else if(strcmp(command, "FILE")==0){
      add_file(heap, last_idx);
    }
    else if(strcmp(command, "REMOVE")==0){
      cout <<"remove();   " << endl;
    }
    else if(strcmp(command,"DISPLAY")==0){
      print(heap, last_idx);
    }
    else if(strcmp(command, "QUIT") ==0){
      break;
    }
  }
  return 0;
}

void add_num(int heap[101],int &last_idx, int num){
  // checks if heap is full
  if(last_idx >= 100){
    cout <<"Heap is full with 100 numbers" << endl;
    return;
  }
  
  heap[last_idx] = num;

  int current = last_idx;
  int parent_idx = (last_idx)/2;

  while(current > 1 && heap[current]>heap[parent_idx]){
    swap(heap,current,parent_idx);
    //after swap update the indexs
    current = parent_idx;  // move up
    parent_idx = current/2;  //recalc parent
  }
  
  last_idx++;
}

void add_file(int heap[101], int &last_idx){
  // ask user for file name then open it
  char filename[80];
  cout <<"Enter file name: " << endl;
  cin >> filename;
  ifstream file(filename);

  int num;

  while(file >> num){
    cout << "hi" << endl;
    cout << num << endl;
    add_num(heap,last_idx,num);
  }

  // close file
  file.close();
  
}


void swap(int heap[101], int a, int b){
  int temp = heap[a];
  heap[a]= heap[b];
  heap[b] = temp;
}


/*
void remove(int heap[101], int &last_idx){
  if(last_idx ==


}
*/


void print(int heap[101], int last_idx){
  for(int i=1; i<last_idx; i++){
    cout << heap[i] << endl;
  }

}
