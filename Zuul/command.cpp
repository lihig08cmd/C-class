/* this is command .cpp    */

#include <iostream>
#include <iostream>
#include "command.h"
using namespace std;

//defult constractor
command::command(){

}

command::command(char* command_word, char* second_word){
  strcpy(commandWord, command_word);
  strcpy(secondWord, second_word);

}

command::getCommandWord(){
  return commandWord;
}

command::getSecondWord(){
  return secondWord;
}

command::isUnKnown(){
  return (commandWord == NULL);
}

command::hasSecondWord(){
  return (secondWord == NULL);
}
