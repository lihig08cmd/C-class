/* this is digitalmedia .cpp  */

#include <iostream>
#include <cstring>
#include "digitalmedia.h"
using namespace std;

// defult constructor
digitalmedia::digitalmedia(){
}

// destructor
digitalmedia::~digitalmedia(){
}

digitalmedia::digitalmedia(char* title_in, int year_in) {
  strcpy(title, title_in);
  year = year_in;
  
}

char* digitalmedia::getTitle(){
  return title;

}

int digitalmedia::getYear(){
  return year;
  
}

//This is the base print function. It will be overridden
void digitalmedia::print(){
}
