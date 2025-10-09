/* Guessing Games
  This progrem will pick a random number for 0 to 100
  and the user will try to guess the number. If the number the user guessed is
  corrent it will show how many attemps it took. If the guess is higher or lower the progrem will tell the user.

  C++ rules -
  1. No global variables
  2. no strings.
  3. You should include <iostream>, not stdio. Also, use "new" and delete" instead of "malloc" and "free"
  
 
 Lihi Gavrielov
 *9/5/25 */

#include <iostream>
#include <cstdlib> //need this for rand() and srand()
#include <ctime> // need this for time()
using namespace std;

int main()
{
  cout << "Welcome to guessing game!" << endl;
  bool play = true;

    while (play == true) {
      // a veriable that keeps track of attepts
      int attepts = 0;

      // get diffrent random numbers everytime the program runs
      srand(time(0));
      // generate random number between 0 and 100 (includeing 1 and 100)
      int randNum = rand() % 101;

      while (true){
	  // a variable to keep the guess
	  int guess;
	  // asks the user to enter number 
	  cout << "Enter a guess (0,100): " << endl;
	  // stors the user input in guess
	  cin >> guess;

	  // adds attepts
	  attepts += 1;

	  // check if the guess is higher, lower, or the right number
	  if (guess < randNum) {
	    cout << "The guess is too low" << endl;
	  }
	  else if (guess > randNum) {
	    cout << "The guess is too high" << endl;
	  }
	  else{
	    cout << "The guess is RIGHT!" << endl;
	    cout << "You geussed " << guess << " in " << attepts << " attempts!" << endl;
	    break;
	  }
      }

      // asks to play again. Than stors the answer here
      string again;
      cout << "Want to play again? (yes or no)" << endl;
      cin >> again;

      // checking if the answer is yes or no
      if (again == "yes"){
	play = true;
      }
      else{
	cout << "Byeeee" << endl;
	play = false;
      }
      
    }      

  return 0;
}
