// this is student .cpp

#include <iostream>
#include <cstring>
#include "Student.h"
using namespace std;

Student::Student(const char* newName, int newId){
  strcpy(name, newName);
  id = newId;
}

void Student::print(){
  cout <<"Name: "<< name << ", ID: " << id << endl;
}
