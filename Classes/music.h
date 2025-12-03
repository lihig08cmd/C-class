/* this is mucis.h  */

#include <iostream>
#include <cstring>
#include "digitalmedia.h"
using namespace std;

class music: public digitalmedia{
 public:
  //default constractor
  music();
  //destractor
  ~music();

  music(char* title_in, int year_in, char* artist_in, double duration_in, char* publisher_in);
  char* getArtist();
  double getDuration();
  char* getPublisher();

  // prints music the info
  void print();

private:
  char artist[80];
  // how long the song is
  double duration;
  char publisher[80];
  
};
