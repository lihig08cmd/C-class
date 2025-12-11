/* this is command .h */

#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <cstring>
using namespace std;

class command {
 public:
  command();
  command(char* first[], char* second[]);
  char commandWord[80];
  char secondWord[80];

  char* getCommandWord();
  char* getsecondWord();

  bool isUnKnown();
  bool hasSecondWord();
};

#endif
