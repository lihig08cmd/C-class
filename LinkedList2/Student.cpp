/*  this is Student .cpp */

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Student.h"
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

void Student::print(){
  cout << first<< ' ' << last<< ", "<< id << ", " << fixed << setprecision(2) << gpa << endl;
}
