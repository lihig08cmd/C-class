/* this is videoGames.cpp */

#include <iostream>
#include <cstring>
#include "videoGames.h"
using namespace std;

videoGames:: videoGames():digitalmedia() {
  cout<< "IN THE VIDEOGAMES -  constractor default" << endl;
}

//videoGames:: videoGames(int year_in):digitalmedia(year_in) {
videoGames:: videoGames(char* title_in,int year_in, char* publisher_in, float rating_in):digitalmedia(title_in ,year_in) {
  cout<< "IN THE VIDEOGAMES -  constractor" << endl;
  rating = rating_in;
  strcpy(publisher,publisher_in);
}

float videoGames::getRating(){
  cout << " In videoGAme.cpp - getRATING" << endl;
  return rating;

}

char* videoGames::getPublisher(){
  cout<< "In videoGAmes.cpp  -   getPublishee" << endl;
  return publisher;
}

void videoGames::print(){
  cout << "Video Games" << endl;
  cout << "Title: " << title << endl;
  cout << "Year: " << year << endl;
  cout << "Publisher: " << publisher << endl;
  cout << "Rating: " << rating << endl;
}
