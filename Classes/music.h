/* this is mucis.h  */

#include <iostream>
#include <cstring>
#include "digitalmedia.h"
using namespace std;

class music: public digitalmedia{
 public:
  music();
  music(char* title_in, int year_in, char* artist_in, float duration_in, char* publisher_in);
  char* getArtist();
  float getDuration();
  char* getPublisher();
  void print();

private:
  char artist[80];
  float duration;
  char publisher[80];
  
};
