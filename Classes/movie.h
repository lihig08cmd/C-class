/* this is movie.h  */

#include <iostream>
#include <cstring>
#include "digitalmedia.h"
using namespace std;

class movie : public digitalmedia{
public:
  movie();
  movie(char* title_in,int year_in, char* director_in, float duration_in, float rating_in);
  char* getDirector();
  float getDuration();
  float getRating();
  void print();
protected:
  char director[80];
  float duration;
  float rating;
};
