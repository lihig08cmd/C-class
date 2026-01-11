/*  this is Student .cpp */

#include <iostream>
#include <cstring>
using namespace std;

Student::Student(char* f, char* l, int i, float g){
  strcpy(first,f);
  strcpy(last, l);
  int id = i;
  float gpa = g;
}

int Student::getID(){
  return id;
}

float Student::getGPA(){
  return gpa;
}
