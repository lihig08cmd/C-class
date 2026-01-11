/* this is student.h */

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>
using namespace std;

class Student{
 private:
  char first[80];
  char last[80];
  int id;
  float gpa;

 public:
  Student(char* f, char* l , int i, float g);

  int getID();
  float getGPA();
  void print();

};
#endif
