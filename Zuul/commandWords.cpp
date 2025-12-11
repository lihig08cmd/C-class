/* this is commandWords .cpp  */

#include <iostream>
#include <cstring>
#include "commandWords.h"
using namespace std;

//costractor
commandWords::commandWords(){
}

bool commandWords::isCommand(char* astring){
  for(int i=0; i<5; i++){
    if(strcmp(validCommands[i], astring) == 0){
      return true;
    }
  }
  return false;
}

void commandWords::showAll(){
  for(int i=0; i<5; i++){
    cout << validCommands[i] << endl;
  }
}

