/* this is room .cpp  */

#include <iostream>
#include <cstring>
#include "room.h"
using namespace std;

room::room(const char desc[]){
  strcpy(description, desc);
  exitCount = 0;
  itemCount =0;
}

void room::setExit(const char* direction, room* neighbor){
  strcpy(exitDirection[exitCount], direction);
  exitRooms[exitCount] = neighbor;
  exitCount++;
  
}

void room::setItem(item item){
  strcpy(items[itemCount], item.getDescription());
  itemCount++;
}

char* room::getShortDescription(){
  return description;
}

char* room::getExitString(){
  // static is used so the array still exists after the function ends
  static char result[200];
  // this is to start the string with "Exit: "
  strcpy(result, "Exit:");

  // loop throguht exits in this room
  for(int i=0; i<exitCount; i++){
    strcat(result, " ");
    // add the exits
    strcat(result, exitDirection[i]);
  }
  return result;
}

char* room::getItemString(){
  static char result[200];
  strcpy(result, "Items:");

  //loop throught all the items in the room
  for (int i=0; i<itemCount; i++){
    // add a space before each item
    strcat(result, " ");
    // add the items name
    strcat(result, items[i]);
  }
  return result;
}

void room::removeItem(char item[]){
  //loop throught all items
  for(int i=0; i<itemCount; i++){
    //check if the item matchs the one to remove
    if(strcmp(items[i], item) == 0){
      // shifting the items left to fill the gap
      for(int j=i; j<itemCount -1; j++){
	// copy each item one spot to the left
	strcpy(items[j], items[j+1]);
      }
      itemCount--;
      return;
    }
    
  }

}


void room::addItem(char item[]){
  //  this copies a new item's name tp put in the next free spot
  strcpy(items[itemCount], item); 
  itemCount++;
}

char* room::getLongDescription(){
  static char result[200]; // to hold discription
  // basically prints
  strcpy(result, "You are ");
  strcat(result, description);
  strcat(result, ".\n");
  strcat(result, getExitString());
  return result;
}

room* room::getExit(char direction[]){
  // loop throguht all exits
  for(int i=0; i<exitCount; i++){
    //check if directions matches
    if(strcmp(exitDirection[i], direction)==0){
      return exitRooms[i];
    }
  }

  return NULL;

}

bool room::hasItem(const char* item){
  for(int i=0; i<itemCount; i++){
    if(strcmp(items[i], item) == 0){
      return true;
    }
  }
  return false;
}
