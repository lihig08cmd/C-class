/* this is commandWords .h   */

#ifndef COMMANDWORDS_H
#define COMMANDWORDS_H

#include <iostream>
#include <cstring>
using namespace std;

class commandWords{
 public:
  commandWords();
  // A constant array that hold all vlid commmand words
  char* validCommands = {"go", "quit", "help", "pick", "drop"};
  bool isCommand(char* aString);
  void showAll();
  
};
#endif
