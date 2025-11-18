/* this is digitalmedia .cpp  */

#include <iostream>
#include <cstring>
#include "digitalmedia.h"
using namespace std;


digitalmedia::digitalmedia(){
  cout<< "this works" << " This is digitalmedia defult" << endl;
}

//digitalmedia::digitalmedia(int year_in){ //char* title_in
digitalmedia::digitalmedia(char* title_in, int year_in) {
  cout<< "this works" << " This is digitalmedia" << endl;
  //title = new char[80];
  strcpy(title, title_in);
  year = year_in;
  
  
}

char* digitalmedia::getTitle(){
  cout << " This is digitalmedia  - getitle" << endl;
  return title;

}

int digitalmedia::getYear(){
  cout << " This is digitalmedia  - getYear" << endl;
  return year;
  
}
