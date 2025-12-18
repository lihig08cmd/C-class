// this is student .cpp

#include <iostream>
#include <cstring>
#include "Student.h"
using namespace std;

Student::Student(){

}

void Student::print(){
  cout <<"Name: "<< name << ", ID: " << id << endl;
}
