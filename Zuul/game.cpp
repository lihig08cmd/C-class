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
  room* baskerball = new room("in the basketball field");
  room* locker = new room("in the locker room");
  room* football = new room("in the foorball field");
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

  theatre.setExit("west", outside);
  theatre.setExit("north", music);

  music.setExit("south", theatre);

  coffee.setExit("east", outside);
  coffee.seetExit("north", cafeteria);

  cafeteria.setExit("south", coffee);
  cafeteria.serExit("north", basketball);

  sitting.setExit("south", cafeteria);
  sitting.setExit("north", basketball);

  basketball.setExit("south", sitting);
  basketball.setExit("east", locker);

  locker.setExit("west", basketball);
  locker.setExit("south", foorball);
  
  football.setExit("north", locker);
  football.setExit("south", outside);

  lab.setExit("north", outside);
  lab.setExit("east", office);
  lab.setExit("west", science);

  office.setExit("west", lab);
  office.setExit("south", principal);

  principal.setExit("north", office);

  science.setExit("east", lab);
  science.setExit("south", math);

  math.setExit("north", science);
  math.setexit("west", hallway);

  hallway.setExit("east", math);
  hallway.setExit("north", secret);

  secret.setExit("south", math);
  

  // start location. Where the game starts
  currentRoom = outside;
}

void game::play(){
  

}
