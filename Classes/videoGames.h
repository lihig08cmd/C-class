/* this is videoGames.h  */

#include <iostream>
#include <cstring>
#include "digitalmedia.h"
using namespace std;

class videoGames : public digitalmedia {
 public :
  // default constractor
  videoGames();
  // destractor
  ~videoGames();

  //constractor that sets title, year, publisher, and rating
  videoGames(char* title_in,int year_in, char* publisher_in, float rating_in);
  float getRating();
  char* getPublisher();
  
  void print();
protected:
  char publisher[80];
  float rating;
};
