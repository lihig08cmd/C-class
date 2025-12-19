// this is Student .h

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>
using namespace std;

class Student{
 private:
  char name[80];
  int id;

 public:
  Student(const char* newName, int newId);
  void print();

};
#endif
