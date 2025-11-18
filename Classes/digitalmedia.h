 /* this is the digitalmedia.h        */

#ifndef DIGITALMEDIA_H
#define DIGITALMEDIA_H

#include <iostream>
#include <cstring>
using namespace std;

class digitalmedia {
public:
  digitalmedia();
  digitalmedia(char* title_in, int year_in);
  //digitalmedia(int year_in);
  char* getTitle();
  int getYear();

protected:
  char title[80];
  int year;

};

#endif
