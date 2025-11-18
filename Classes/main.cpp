/*   main class

     */


#include <iostream>
#include <cstring>
#include <vector>
// include the other classes
#include "digitalmedia.h"
#include "videoGames.h"
#include "movie.h"
#include "music.h"
using namespace std;



int main(){

  // creating vector
  vector<digitalmedia*> vect;


  char* title1  = new char[80];
  strcpy(title1, "Mario");
  int year1 = 2010;
  char* publisher1 = new char[80];
  strcpy(publisher1, "Nintendo");
  float rating1 = 8.5;

    // creating a pointer of videoGames
  videoGames* vg1 = new videoGames(title1, year1, publisher1, rating1);

  //videoGames* vg1 = new videoGames(year1);
  

  vect.push_back(vg1);

  cout << vg1->getYear() << endl;
  cout << vg1->getTitle() << endl;
  cout << vg1->getPublisher() << endl;
  cout << vg1->getRating() << endl;

  cout << "-------------------------------------" << endl;

  vg1->print();

  cout << "----------------------" << endl;

  char* movTitle = new char[80];
  strcpy(movTitle, "10 things");
  int movYear = 1999;
  char* movDirector = new char[80];
  strcpy(movDirector, "Ella Young");
  float movDuration = 1.30;
  float movRating = 9.5;

  // creating poinmter
  movie* mov1 = new movie(movTitle, movYear, movDirector, movDuration, movRating);

  // 
  vect.push_back(mov1);

  cout << mov1->getYear() << endl;
  cout << mov1->getDirector()<< endl;
  cout << mov1->getDuration() << endl;

  cout << "......................." << endl;

  mov1->print();

  cout << "]]]]]]]]]]]]]]]]]]]]]]" << endl;

  char* musTitle = new char[80];
  strcpy(musTitle, "7 rings") ;
  int musYear = 2019;
  char* musArtist = new char[80];
  strcpy(musArtist, "Ariana");
  float musDuration = 3.5;
  char* musPub = new char[80];
  strcpy(musPub, "HYBE");

  // creat pointer
  music* mus1 = new music(musTitle, musYear, musArtist, musDuration, musPub);

  vect.push_back(mus1);

  mus1->print();
}
     
