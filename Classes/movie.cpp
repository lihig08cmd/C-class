/*  this is movie.cpp */

#include <iostream>
#include <cstring>
#include "movie.h"
using namespace std;

// defualt constructor
movie:: movie(): digitalmedia(){
}

// destructor
movie::~movie(){
}

movie:: movie(char* title_in,int year_in, char* director_in, double duration_in, float rating_in):digitalmedia(title_in ,year_in){
  strcpy(director, director_in);
  duration = duration_in;
  rating = rating_in;
}

char* movie::getDirector(){
  return director;

}

double movie::getDuration(){
  return duration;
}

float movie::getRating(){
  return rating;
}

// prints mvoie info
void movie::print(){
  cout<< "Movies" << endl;
  cout << "Title: " << title << endl;
  cout << "Year: " << year << endl;
  cout << "Director: " << director << endl;
  cout << "Duration: " << duration << endl;
  cout << "Rating: " << rating << endl;
}
