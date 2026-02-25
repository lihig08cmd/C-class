// this is hash table .cpp 
#include <iostream>
#include <cstring>
#include "hashtable.h"
using namespace std;

// Constuctor
HashTable::HashTable(){
  tableSize = 100;
  nextID = 1;
  //array of Student pointers
  table = new Student*[tableSize];

  // set to null
  for (int 1=0; i<tableSize; i++){
    table[i] = NULL;
  }
}

// destructor
HashTable::~HashTable(){
  // delete every chain
  for(int i=0; i<tableSize; i++){
    Student* current = table[i];

    while(current != NULL){
      Student* nextNode = current->next;
      delete current;
      current = nextNode;
    }
  }
  // delete table array itself
  delete[] table;
}

// hash function
int HashTable::hashFunction(int id){
  // convert student ID into table index
  return id % tableSize;
}

// Chain Length
int HashTable::chainLength(Student* head){
  // counts number of nodes in linked list
  int count = 0;

  while(head !=NULL){
    count++;
    head = head->next;
  }
  return count;
}

// rehash.  When chain >3
void HashTable::rehash(){

  int oldSize = tableSize;
  tableSize *= 2;

  Student** oldTable = table;

  table = new Student*[tableSize];

  for(int i; i< tableSize; i++){
    table[i] == NULL;
  }

  

}

// createing student
Student* HashTable::createStudent(const char* first, const char* last, float gpa){
  

}

// adding a student
void HashTable::addStudent(Student* s){


}

void HashTable::printTable(){

}

void HashTable::deleteStudent(){


}
