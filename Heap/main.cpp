// Heap

#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream> 
using namespace std;

// functions prototypes
void add_num(int heap[101],int &last_idx, int num); //adds num to the heap in "last place
void add_file(int heap[101], int &last_idx); //add numbers from file to heap 
void remove(int heap[101], int &last_idx);// remove root
void remove_all(int heap[101], int &last_idx);  //remove everything
void print(int heap[101], int index, int last_idx, int depth); //print tree
void swap(int heap[101], int a, int b); // swapping 


int main(){
  int heap[101];
  int last_idx = 1;  

  while(true){
    char command[80];
    cout << "Enter command(To add-NUMBER/FILE, REMOVE, REMOVEALL DISPLAY, QUIT)"<< endl;
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
      remove(heap, last_idx);
    }
    else if(strcmp(command, "REMOVEALL") ==0){
      remove_all(heap, last_idx);
    }
    else if(strcmp(command,"DISPLAY")==0){
      print(heap, 1,last_idx,0);
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
    parent_idx = current/2;  //find new parent
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


// this function prints the largest num and then removes the root
void remove(int heap[101], int &last_idx){
  //check if empty
  if(last_idx == 1){
    cout << "Heap is empty" << endl;
    return;
  }

  //print the largest
  cout << heap[1] << endl;

  //reduce size
  last_idx--;
  //move last to root
  heap[1] = heap[last_idx];

  int current = 1;
  
  while(true){
    int left = current *2;
    int right = current *2+1;
    int largest = current;

    //checking left child
    if(left < last_idx && heap[left] > heap[largest]){
      largest = left;
    }

    //checking right child
    if(right < last_idx && heap[right] > heap[largest]){
      largest = right;
    }

    // already in the right spot
    if(current == largest){
      break;
    }
    swap(heap, current, largest);
    //move down
    current = largest;
  }
}

void remove_all(int heap[101], int &last_idx){
  // repeatedly remove root and also prints the largest each time
  while(last_idx >1){
    remove(heap, last_idx);
  }
}

void print(int heap[101], int index, int last_idx, int depth){
  if(index >= last_idx){
    return;
  }

  //right child
  print(heap, index*2+1, last_idx, depth+1);

  for(int i=0; i<depth; i++){
    cout << "\t";
  }
  cout << heap[index] << endl;

  // left child
  print(heap, index*2, last_idx, depth+1);
}
