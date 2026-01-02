/* this is item .h */

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>
using namespace std;

class item{
 public:
  item();
  item(char desc[]);

  char description[80];

  char* getDescription();
  

};
#endif
