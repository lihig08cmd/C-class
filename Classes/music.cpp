/*  this is music .cpp */

#include <iostream>
#include <cstring>
#include "music.h"
using namespace std;

music::music():digitalmedia(){
  
}

music::music(char* title_in, int year_in, char* artist_in, float duration_in, char* publisher_in):digitalmedia(title_in ,year_in){
  strcpy(artist, artist_in);
  duration = duration_in;
  strcpy(publisher,publisher_in);
}

char* music::getArtist(){
  return artist;
}

float music::getDuration(){
  return duration;
}

char* music::getPublisher(){
  return publisher;
}

void music::print(){
    cout << "Music" << endl;
  cout << "Title: " << title << endl;
  cout << "Year: " << year << endl;
  cout << "Artist: " << artist << endl;
  cout << "Duration: " << duration << endl;
  cout << "Publisher: " << publisher << endl;
}
