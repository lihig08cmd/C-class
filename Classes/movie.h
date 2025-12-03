/* this is movie.h  */

#include <iostream>
#include <cstring>
#include "digitalmedia.h"
using namespace std;

class movie : public digitalmedia{
public:
  movie();
  ~movie();

  //sets the title year, director, duration, and rating
  movie(char* title_in,int year_in, char* director_in, double duration_in, float rating_in);
  char* getDirector();
  double getDuration();
  float getRating();
  
  void print();
protected:
  char director[80];
  // how long the movie is
  double duration;
  float rating;
};
