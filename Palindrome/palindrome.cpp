/* This program will remove any spaces/punctuation and check if the user input is a palindrome or not.

   Name: Lihi Gavrielov
   Date: 9/18/25   */



#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  char input[80];
  char input2[80];
  char input3[80];
  int count = 0;

  // user input
  cin.get(input, 80);



  // this will remove any spaces or punctuation
  // for every char in the input
  for (int i =0; i < strlen(input); i++) {
    if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z')) {
      // if uppercase, it will convert to lowercase
      if (input[i] >= 'A' && input[i] <= 'Z'){
      // add them to input2
      input2[count] = input[i] + ('a' - 'A');
    }
    else{
      input2[count] = input[i];
    }

    count++;
     
  }
  }
  
  // len variable
  int input2len = strlen(input2);

  // this will put all the charactors in backwords
  for (int i= 0; i < input2len; i++) {
    input3[input2len - 1 - i] = input2[i];
    //cout << "somthing else" <<endl;

  }

  //cout << input2 <<endl;
  //cout << input3 << endl;

  
  //This checks if the user input is a palindrome 
  if (strcmp(input2, input3) ==0) {
    cout << "Palindrome." << endl;
  } else {
    cout <<"Not a palindrome." <<endl;
  }

  return 0;
	    
}
