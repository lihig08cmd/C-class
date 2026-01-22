/* this is room . h    */

#ifndef ROOM_H
#define ROOM_H


#include <iostream>
#include <cstring>
#include "item.h"
using namespace std;

class room{
 public:

  room(const char desc[]);
  
  char description[100];
  // exit directions and rooms they lead to
  char exitDirection[10][20];  // 10 words that can lead up tp 20 charaters
  room* exitRooms[10];
  int exitCount;

  // items in the room
  char items[10][50];
  int itemCount;

  void setExit(const char* direction, room* neighbor);
  void setItem(item item);

  char* getShortDescription();
  char* getExitString();
  char* getItemString();

  void removeItem(char item[]);
  void addItem(char item[]);

  char* getLongDescription();

  room* getExit(char direction[]);

  bool hasItem(const char* item);

};
#endif
