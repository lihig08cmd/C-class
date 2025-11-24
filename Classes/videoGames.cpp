/* this is videoGames.cpp */

#include <iostream>
#include <cstring>
#include "videoGames.h"
using namespace std;

// default constractor
videoGames:: videoGames():digitalmedia() {
}
// destructor
videoGames:: ~videoGames(){
}

// passes title and year and sets publisher and rating
videoGames:: videoGames(char* title_in,int year_in, char* publisher_in, float rating_in):digitalmedia(title_in ,year_in) {
  rating = rating_in;
  strcpy(publisher,publisher_in);
}

float videoGames::getRating(){
  //cout << " In videoGAme.cpp - getRATING" << endl;
  return rating;

}

char* videoGames::getPublisher(){
  //cout<< "In videoGAmes.cpp  -   getPublishee" << endl;
  return publisher;
}

// prints all video game info
void videoGames::print(){
  cout << "Video Games" << endl;
  cout << "Title: " << title << endl;
  cout << "Year: " << year << endl;
  cout << "Publisher: " << publisher << endl;
  cout << "Rating: " << rating << endl;
}
