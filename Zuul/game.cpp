/* this is game .cpp  */

#include <iostream>
#include <cstring>
using namespace std;
#include "game.h"

char* inventory[50];
int inventoryCount = 0;

//constructor
game::game(){
  creatRooms();
  creatItems();
}

void game::creatRooms(){
  outside = new room("outside the main entrance");
  theatre = new room("in a lecture theatre");
  coffee = new room("in the campus coffee house");
  lab = new room("in the computing lab");
  office = new room("in the computing admin office");
  music = new room("in the music room");
  cafeteria = new room("in the campus cafeteria");
  sitting = new room("in the setting area");
  basketball = new room("in the basketball field");
  locker = new room("in the locker room");
  football = new room("in the football field");
  principal = new room("in the principal office");
  science = new room("in the science class");
  math = new room("in the math class");
  hallway = new room("in the hallway");
  secret = new room("in the SECRET room!!!");

  //exits
  outside->setExit("east", theatre);
  outside->setExit("south", lab);
  outside->setExit("west", coffee);
  outside->setExit("north", football);

  theatre->setExit("west", outside);
  theatre->setExit("north", music);

  music->setExit("south", theatre);

  coffee->setExit("east", outside);
  coffee->setExit("north", cafeteria);

  cafeteria->setExit("south", coffee);
  cafeteria->setExit("north", sitting);

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

void game::creatItems(){
  //create items
  item leaf("leaf");
  item costume("costume");
  item goldCoin("GoldCoin");
  item cup("cup");
  item food("food");
  item bronzeCoin("bronzeCoin");
  item hint1("Hint1");
  item clothes("clothes");
  item computers("computers");
  item pens("pens");
  item hint2("Hint2");
  item silverCoin("silverCoin");
  item calculater("calculater");
  item emptyPaper("emptyPaper");
  item hint3("Hint3");
  item foot_ball("foot ball");

  // put them in rooms
  outside->setItem(leaf);
  theatre->setItem(costume);
  music->setItem(goldCoin);
  coffee->setItem(cup);
  cafeteria->setItem(food);
  sitting->setItem(bronzeCoin);
  sitting->setItem(hint1);
  basketball->setItem(goldCoin);
  locker->setItem(clothes);
  football->setItem(foot_ball);
  lab->setItem(computers);
  office->setItem(pens);
  principal->setItem(hint2);
  principal->setItem(silverCoin);
  science->setItem(silverCoin);
  math->setItem(calculater);
  math->setItem(goldCoin);
  hallway->setItem(emptyPaper);
  secret->setItem(hint3);
  secret->setItem(goldCoin);
  
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
    cout << "Goodbye!" << endl;
    exit(0);
  }

  return false;  

}

void game::printHelp(){
  cout << "Your command words are:" << endl;
  // ask parper to print all valid command
  parser.showCommands();
}

void game::printInventory(){
  cout << "Inventory: ";
  // loop throguht all iteams the player has
  for(int i=0; i<inventoryCount; i++){
    cout << " " <<inventory[i]; 
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
  inventory[inventoryCount] = new char[strlen(item) +1];
  strcpy(inventory[inventoryCount], item);
  inventoryCount++;

  //remove item form the room
  currentRoom->removeItem(item);

  //Print updated information
  cout << currentRoom->getLongDescription() << endl;
  cout << currentRoom->getItemString() << endl;
  printInventory();

  // prints hint
  if(strcmp(item, "Hint1")==0){
    cout << endl;
    cout << "Hint1: Maybe collecting coins is important..." << endl;
  }
  else if(strcmp(item,"Hint2")==0){
    cout << endl;
    cout << "Hint2: Some rooms may hide valuable items" << endl;
  }
  else if(strcmp(item, "Hint3") ==0){
    cout << endl;
    cout << "Hint3: Three gold coins might get you a win" << endl;
  }

  // check win condition (if the player collected 3 gold coints)
  if(countGoldCoins() == 3){
    cout << endl;
    cout << "YOU WIN!!!! You collected 3 Gold Coints!" << endl;
    cout << "You can choose to look around or quit! Thanks for playing!" << endl;
  }

  
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

  //winning condition
int game::countGoldCoins(){
  int count = 0;
  // loop throguht each item in inventory
  for(int i=0; i <inventoryCount; i++){
    // check to see if it is GoldCoin
    if(strcmp(inventory[i], "GoldCoin") ==0){
      // add it to count
      count++;
    }
  }
  return count;
}
