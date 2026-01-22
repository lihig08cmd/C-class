/* this is parser . h    */

#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <cstring>
#include "command.h"
#include "commandWords.h"
using namespace std;

class parser{
 public:
  commandWords commands;
  
  parser();

  // reads the input and returns a command
  command getCommand();
  void showCommands();
  
};
#endif
