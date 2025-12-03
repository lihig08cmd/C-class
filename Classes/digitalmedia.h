 /* this is the digitalmedia.h        */

#ifndef DIGITALMEDIA_H
#define DIGITALMEDIA_H

#include <iostream>
#include <cstring>
using namespace std;

class digitalmedia {
public:
  digitalmedia();
  virtual ~digitalmedia();
  
  digitalmedia(char* title_in, int year_in);
  //digitalmedia(int year_in);
  char* getTitle();
  int getYear();

  virtual void print();

protected:
  char title[80];
  int year;

};

#endif
