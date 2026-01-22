/* this is game .h */

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstring>
using namespace std;
#include "commandWords.h"
#include "command.h"
#include "parser.h"
#include "room.h"
#include "item.h"

class game{
private:
  // reads user commands
  parser parser;
  // pointer to the room the player is in
  room* currentRoom;

public:
  game();

  void creatItems();
  void creatRooms();
  void play();
  void printWelcome();
  bool processCommand(command command);
  void printHelp();
  void printInventory();
  void goRoom(command command);
  void pickItem(command command);
  void dropItem(command command);
  bool quitGame(command command);

};
#endif
