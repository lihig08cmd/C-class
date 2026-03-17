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
  for (int i=0; i<tableSize; i++){
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
  //double the table size
  tableSize *= 2;

  //save pointer to the onld table
  Student** oldTable = table;

  //createing a new bigger table
  table = new Student*[tableSize];

  for(int i; i< tableSize; i++){
    table[i] = NULL;
  }

  //go thrgouht every slot of the old table
  for(int i=0; i< oldSize; i++){
    
    Student* current = oldTable[i];

    while(current != NULL){
      Student* nextNode = current->next;

      //new index based on new table size
      int index = hashFunction(current->id);

      //put node into the new table
      current->next = table[index];
      table[index] = current;

      current = nextNode;
    }

  }
  // delete the old table
  delete[] oldTable;
}



// createing student
Student* HashTable::createStudent(const char* first, const char* last, float gpa){
  Student* s = new Student;

  strcpy(s->first, first);
  strcpy(s->last, last);

  s->gpa = gpa;
  s->id = nextID++;
  s->next = NULL;

  return s;
}

// adding a student
void HashTable::addStudent(Student* s){
  int index = hashFunction(s->id);

  // put at the head of the chain
  s->next = table[index];
  table[index] = s;

  //check collision
  if(chainLength(table[index]) >3){
    rehash();
  }
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

void HashTable::deleteStudent(int id){
  int index  = hashFunction(id);

  Student* current = table[index];
  Student* prev = NULL;

  while(current != NULL){
    if(current->id == id){
      if(prev==NULL){
	table[index]=current->next;
      }
      else{
	prev->next = current->next;
      }
      delete current;
      cout <<"Student has been deleted" <<endl;
      return;
    }
    prev = current;
    current = current->next;
  }
  cout <<"student not found"<< endl;
}
