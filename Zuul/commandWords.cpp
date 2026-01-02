/* this is commandWords .cpp  */

#include <iostream>
#include <cstring>
#include "commandWords.h"
using namespace std;

//costractor
commandWords::commandWords(){
}

bool commandWords::isCommand(char* astring){
  // loop throguht all command words
  for(int i=0; i<5; i++){
    // compare the input string with the current valid command 
    if(strcmp(validCommands[i], astring) == 0){
      return true;
    }
  }
  // command was not found
  return false;
}

void commandWords::showAll(){
  // loop throguht all commands
  for(int i=0; i<5; i++){
    // print each command
    cout << validCommands[i] << endl;
  }
}

