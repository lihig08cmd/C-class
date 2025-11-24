/*  this is music .cpp */

#include <iostream>
#include <cstring>
#include "music.h"
using namespace std;

// defualt constractor
music::music():digitalmedia(){
  
}

//destractor
music::~music(){

}

music::music(char* title_in, int year_in, char* artist_in, double duration_in, char* publisher_in):digitalmedia(title_in ,year_in){
  // copy artist string into array
  strcpy(artist, artist_in);
  //store duration
  duration = duration_in;
  // copy publisher string into publisher array
  strcpy(publisher,publisher_in);
}

char* music::getArtist(){
  return artist;
}

double music::getDuration(){
  return duration;
}

char* music::getPublisher(){
  return publisher;
}

//prints music info
void music::print(){
    cout << "Music" << endl;
  cout << "Title: " << title << endl;
  cout << "Year: " << year << endl;
  cout << "Artist: " << artist << endl;
  cout << "Duration: " << duration << endl;
  cout << "Publisher: " << publisher << endl;
}
