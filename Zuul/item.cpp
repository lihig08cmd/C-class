/* this is item.cpp  */

#include <iostream>
#include <cstring>
#include "item.h"
using namespace std;


item::item(){
  description[0] = '\0';
}

item::item(const char* desc){
  strcpy(description, desc);
}

char* item::getDescription(){
  return description;
}
