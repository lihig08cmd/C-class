/* this is main class for the game zuul.

   my code is based on the python zuul code from last year.

   Lihi Gavrielov
   1/21/26      */

#include <iostream>
#include <cstring>
using namespace std;
// include all the other classes
#include "parser.h"
#include "command.h"
#include "commandWords.h"
#include "room.h"
#include "item.h"
#include "game.h"

int main(){
  // create the game object
  game g;

  //start the game
  g.play();
  return 0;
}
