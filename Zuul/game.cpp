/* this is game .cpp  */

#include <iostream>
#include <cstring>
using namespace std;
#include "game.h"

char* inventory[50];
int inventoryCount = 0;

//constructor
game::game(){
  creatItems();
  creatRooms();
}

void game::creatItems(){


}

void game::creatRooms(){
  room* outside = new room("outside the main entrance");
  room* theatre = new room("in a lecture theatre");
  room* coffee = new room("in the campus coffee house");
  room* lab = new room("in the computing lab");
  room* office = new room("in the computing admin office");
  room* music = new room("in the music room");
  room* cafeteria = new room("in the campus cafeteria");
  room* sitting = new room("in the setting area");
  room* basketball = new room("in the basketball field");
  room* locker = new room("in the locker room");
  room* football = new room("in the football field");
  room* principal = new room("in the principal office");
  room* science = new room("in the science class");
  room* math = new room("in the math class");
  room* hallway = new room("in the hallway");
  room* secret = new room("in the SECRET room!!!");

  //exits
  outside->setExit("east", theatre);
  outside->setExit("south", lab);
  outside->setExit("west", coffee);
  outside->setExit("noeth", football);

  theatre->setExit("west", outside);
  theatre->setExit("north", music);

  music->setExit("south", theatre);

  coffee->setExit("east", outside);
  coffee->setExit("north", cafeteria);

  cafeteria->setExit("south", coffee);
  cafeteria->setExit("north", basketball);

  sitting->setExit("south", cafeteria);
  sitting->setExit("north", basketball);

  basketball->setExit("south", sitting);
  basketball->setExit("east", locker);

  locker->setExit("west", basketball);
  locker->setExit("south", football);
  
  football->setExit("north", locker);
  football->setExit("south", outside);

  lab->setExit("north", outside);
  lab->setExit("east", office);
  lab->setExit("west", science);

  office->setExit("west", lab);
  office->setExit("south", principal);

  principal->setExit("north", office);

  science->setExit("east", lab);
  science->setExit("south", math);

  math->setExit("north", science);
  math->setExit("west", hallway);

  hallway->setExit("east", math);
  hallway->setExit("north", secret);

  secret->setExit("south", math);
  

  // start location. Where the game starts
  currentRoom = outside;
}

void game::play(){
  printWelcome();

  //controls when the game ends
  bool finished = false;

  // running while the game is NOT finished
  while(!finished){
    //read a commend from the user
    command cmd = parser.getCommand();
    //ending the loop if true
    finished = processCommand(cmd);
  }

  cout << "thank you for playing. Goodbye" << endl;
}

void game::printWelcome(){
  cout << endl;
  cout << "Welcome! to Adventure" << endl;
  cout << "Type 'help' if you need help." << endl;
  cout << endl;

  cout << currentRoom->getLongDescription()<< endl;
  cout << currentRoom->getItemString()<< endl;
  printInventory();
}

bool game::processCommand(command commandObj){
  // if command is un known
  if(commandObj.isUnKnown()){
    cout << "I don't know what you mean..." << endl;
    return false;
  }

  // get the first word of the command
  char* commandWord = commandObj.getCommandWord();

  // check which command word
  if(strcmp(commandWord, "help") ==0){
    printHelp();
  }
  else if(strcmp(commandWord, "go") == 0){
    goRoom(commandObj);
  }
  else if (strcmp(commandWord, "pick") ==0){
    pickItem(commandObj);
  }
  else if (strcmp(commandWord, "drop") ==0){
    dropItem(commandObj);
  }
  else if (strcmp(commandWord, "quit") ==0){
    return quitGame(commandObj);
  }

  return false;  

}

void game::printHelp(){
  cout << "Your command words are:" << endl;
  // ask parper to print all valid command
  parser.showCommands();
}

void game::printInventory(){
  cout << "Inventory: : " << endl;
  // loop throguht all iteams the player has
  for(int i=0; i<inventoryCount; i++){
    cout << inventory[i]; 
  }
}

void game::goRoom(command commandObj){
  // if not direction was giving
  if(!commandObj.hasSecondWord()){
    cout << "Go where?"<< endl;
    return;
  }

  // get direction
  char* direction = commandObj.getSecondWord();

  //see if the current room has an exit in that direction
  room* nextRoom = currentRoom->getExit(direction);

  // if ther eis not room
  if(nextRoom == NULL){
    cout << "There is no door!" << endl;
  }
  else{
    // move player to the new room
    currentRoom = nextRoom;

    //print new room information
    cout << currentRoom->getLongDescription() << endl;
    cout << currentRoom->getItemString() << endl;
    printInventory();
  }
}

void game::pickItem(command commandObj){

  //if player didnt say which item
  if(!commandObj.hasSecondWord()){
    cout << "Which item to pick" << endl;
    return;
  }

  //get the item name
  char* item = commandObj.getSecondWord();

  //check if the item exists in the room
  if(!currentRoom->hasItem(item)){
    cout << "No such item in the room!"<< endl;
    return;
  }

  // add item to inventory
  inventory[inventoryCount] = item;
  inventoryCount++;

  //remove item form the room
  currentRoom->removeItem(item);

  //Print updated information
  cout << currentRoom->getLongDescription() << endl;
  cout << currentRoom->getItemString() << endl;
  printInventory();
}

void game::dropItem(command commandObj){
  //if player didn't say which item
  if(!commandObj.hasSecondWord()){
    cout <<"Which item to drop?" << endl;
    return;
  }

  char* item = commandObj.getSecondWord();
  bool found = false;

  // search inventory for item
  for(int i=0; i<inventoryCount; i++){
    if(strcmp(inventory[i], item)==0){
      found = true;

      //add item back to the room
      currentRoom->addItem(item);

      //remove item from inventory by shifting left
      for(int j=i; j<inventoryCount -1; j++){
	inventory[i] = inventory[j+1];
      }
      inventoryCount--;
      break;
    }
  }

  //if item wasn't in inventory
  if(!found){
    cout << "You don't have that item!" << endl;
    return;
  }

  //Print updated information
  cout << currentRoom->getLongDescription() << endl;
  cout << currentRoom->getItemString() << endl;
  printInventory();
}

bool game::quitGame(command commandObj){
  //if user typed "quit something"
  if(commandObj.hasSecondWord()){
    cout << "Quit what? " << endl;
    return false;
  }
  return false;
}
