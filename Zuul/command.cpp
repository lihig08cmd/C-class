/* this is command .cpp    */

#include <iostream>
#include <iostream>
#include "command.h"
using namespace std;

//defult constractor
command::command(){
  commandWord[0] = '\0';
  secondWord[0] = '\0';
}

command::command(char* first[], char* second[]){
  strcpy(commandWord, first);
  strcpy(secondWord, second);

}

char* command::getCommandWord(){
  return commandWord;
}

char* command::getSecondWord(){
  return secondWord;
}

bool command::isUnKnown(){
  return (commandWord[0] == '\0');
}

bool command::hasSecondWord(){
  return (secondWord[0] == '\0');
}
