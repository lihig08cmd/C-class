/*   main class

     Lihi Gavrielov
     11/23/25

 */
#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
// include the other classes
#include "digitalmedia.h"
#include "videoGames.h"
#include "movie.h"
#include "music.h"
using namespace std;

// functions prototype
void add(vector<digitalmedia*>& vect );
void search(vector<digitalmedia*>& vect );
void delete_fun(vector<digitalmedia*>& vect );

int main(){

  // creating vector of parent pointers
  vector<digitalmedia*> vect;

  while(true){

    // user input
    char input[80];
    cout << "Would you like to add, search, delete, or quit? (Enter 1, 2, 3, or 4): " << endl;
    cin >> input;

    // add
    if (strcmp(input, "1") ==0){
      add(vect);
    }
    // search
    else if (strcmp(input, "2") ==0){
      search(vect);
    }
    // delete
    else if (strcmp(input, "3")==0){
      delete_fun(vect);
    }
    // quit
    else if (strcmp(input, "4")==0){
      cout << "Byee!" << endl;
      return 0;
    }
    // invalid input
    else{
      cout << "Try again." << endl;
    }
  }
  return 0;
}
     
// add function
void add(vector<digitalmedia*>& vect) {

  // ask the user what to add
  char type[80];
  cout << "Type: 1 for video game, 2 for music, 3 for movie: " << endl;
  cin >> type;

  // if video game
  if (strcmp(type, "1") == 0){

    char title[80];
    int year;
    char publisher[80];
    float rating;

    cin.ignore(80, '\n');

    cout << "Enter title: " << endl;
    cin.getline(title, 80);

    cout << "Enter year: " << endl;
    cin >> year;

    cin.ignore(80, '\n');
    
    cout << "Enter publisher: " << endl;
    cin.getline(publisher, 80);

    cout << "Enter rating: " << endl;
    cin >> rating;

    cin.ignore(80, '\n');

    
    videoGames* vg = new videoGames(title, year, publisher, rating);
    vect.push_back(vg);

    cout << "Video game added" << endl;
    
  }

  // if music
  else if (strcmp(type, "2") == 0){

    char title[80];
    int year;
    char artist[80];
    double duration;
    char publisher[80];

    cin.ignore(80,'\n');
    
    cout << "Enter title: " << endl;
    cin.getline(title, 80);

    cout << "Enter year: " << endl;
    cin >> year;

    cin.ignore(80, '\n');
    cout << "Enter artist: " << endl;
    cin.getline(artist, 80);

    cout << "Enter duration: " << endl;
    cin >> duration;

    cin.ignore(80, '\n');
    cout << "Enter publisher: " << endl;
    cin.getline(publisher, 80);

    //cin.ignore(80, '\n');

    music* mus = new music(title, year, artist, duration, publisher);
    vect.push_back(mus);

    cout << "Music added" << endl;
  }

  // if movie
  else if (strcmp(type, "3") ==0){

    char title[80];
    int year;
    char director[80];
    double duration;
    float rating;

    cin.ignore(80, '\n');

    cout << "Enter title: " << endl;
    cin.getline(title, 80);

    cout << "Enter year: " << endl;
    cin >> year;

    cin.ignore(80, '\n');
    cout << "Enter director: " << endl;
    cin.getline(director, 80);

    cout << "Enter duration: " << endl;
    cin >> duration;

    cout << "Enter rating: " << endl;
    cin >> rating;

    cin.ignore(80, '\n');

    movie* mov = new movie(title, year, director, duration, rating);
    vect.push_back(mov);

  }

  else{
    cout << "invalid type" << endl;
  }

}


// search function
void search(vector<digitalmedia*>& vect){

  char type[20];
  cout << "Search by title OR year: " << endl;
  cin >> type;

  // clears the left over
  cin.ignore(80, '\n');
  
  if (strcmp(type, "title") ==0 || strcmp(type, "Title")==0){
    char title[80];
    // ask for the title
    cout << "Enter title to search: " << endl;
    cin.getline(title, 80);

    // goes through all stored digitel media 
    for(int i =0; i < vect.size(); i++){
      //compares the stored title with the title the user put in
      if(strcmp(vect[i]->getTitle(), title)==0){
	//prints it out
	vect[i]->print();
	cout << endl;
      }
    }
  }

  else if (strcmp(type, "year") ==0 || strcmp(type, "Year") ==0){
    int year;
    cout << "Enter year to search: " << endl;
    cin >> year;

    //loops thought digitel media
    for (int i=0; i<vect.size(); i++){
      //checks if the years match
      if(vect[i]->getYear() == year){
	// prints out
	vect[i]->print();
	cout << endl;
      }
    }
  }
  else{
    cout << "Invalid search type" << endl;
  }
}


// delete function
void delete_fun(vector<digitalmedia*>& vect){

  char type[10];
  cout << "Delete by title or year? " << endl;
  cin >> type;

  cin.ignore(80, '\n');
  
  if (strcmp(type, "title") ==0 || strcmp(type, "Title")==0){
    char title[80];
    cout << "Enter title to delete: " << endl;
    cin.getline(title, 80);

    // goes theough all digital media 
    for(int i=0; i < vect.size(); i++){
      ////compares the stored title with the title the user put in
      if(strcmp(vect[i]->getTitle(), title) == 0){
	// print out to make sure they know what they are deleteing
	vect[i]->print();
	cout << endl;

	char input[20];
	cout << "Is this what you want to delete? (yes or no): " << endl;
	cin >> input;

	if (strcmp(input, "yes") ==0 || strcmp(input, "Yes") ==0){
	  // free memory
	  delete vect[i];
	  // erase from vector
	  vect.erase(vect.begin() +i);
	  cout << "It's deleted" << endl;
	  return;
	}
      }
    }

  }

  // delete by year
  else if (strcmp(type, "year") ==0 || strcmp(type, "Year") == 0){
    int year;
    cout << "Enter year to delete: " << endl;
    cin >> year;

    // goes through digitalmedia 
    for(int i=0; i < vect.size(); i++){
      // checks if matchs
      if(vect[i]->getYear() == year){
        vect[i]->print();
        cout << endl;

	// makes sure they know whats being deleted
        char input[20];
        cout << "Is this what you want to delete? (yes or no): " << endl;
        cin >> input;

        if (strcmp(input, "yes") ==0 || strcmp(input, "Yes") ==0){
	  // free memory
          delete vect[i];
	  //erase from vector
          vect.erase(vect.begin() +i);
          cout << "It's deleted" << endl;
          return;
        }
      }
    }
  }

  else{
    cout <<"invalid delete type" << endl;
  }
}





























