// this is hashtable .h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <cstring>
#include <iostream>
using namespace std;

// this stract represents one student node
struct Student{
  char first[20];
  char last[20];
  int id;
  float gpa;

  // pointer to the next node
  Student* next;

};

class HashTable{
private:
  //
  Student** table;
  int tableSize;
  int nextID;

  int hashFunction(int id);
  void rehash();
  int chainLength(Student* head);

public:
  // constructor / Destructor
  HashTable();
  ~HashTable();

  // create student, Add, print, delete
  Student* createStudent(const char* first, const char* last, float gpa);
  void addStudent(Student* s);
  void printTable();
  void deleteStudent(int id);
  
  // random generator
  //void generateRandom(int count);
  
};
#endif

