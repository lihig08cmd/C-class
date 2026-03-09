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
/*
void HashTable::rehash(){

  int oldSize = tableSize;
  tableSize *= 2;

  Student** oldTable = table;

  table = new Student*[tableSize];

  for(int i; i< tableSize; i++){
    table[i] == NULL;
  }

  for(int i; i<oldTable; i++){
    
    Student* current = oldTable[i];

    while(current != NULL){
      student* nextNode = current->next;
      
    }

  }

  

}

*/

// createing student
Student* HashTable::createStudent(const char* first, const char* last, float gpa){
  Student* s = new Student;

  strcpy(s->first, first);
  strcpy(s->last, last);

  s->gpa = gpa;
  s_>id = nextID++;
  s->next = NULL;

  return s;
}

// adding a student
void HashTable::addStudent(Student* s){
  int index = hashStudent(student*s);

  // put at the head of the chain
  s->next = table[index];
  table[index] = s;

  //check collision
  if(chainLength(table[index]) >3){
    rehash();
}

void HashTable::printTable(){
  for(int i=0; i<tableSize; i++){
    Student* current = table[i];
    while (current != NULL){
      cout <<"ID: " << current->id<< endl;
      cout <<"First name: "<< current->first<< endl;
      cout <<"Last name: " << current->last << endl;
      cout <<"GPA: " << current->gpa<< endl;

      current = current->next;
    }
  }
  
}

void HashTable::deleteStudent(){


}
