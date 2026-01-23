/* this is parser . cpp    */

#include <iostream>
#include <cstring>
#include "parser.h"
using namespace std;

parser::parser(){
}

command parser:: getCommand(){
  // will hold the full input line
  char inputLine[100];
  char word1[80] = "";
  char word2[80] = "";

  //print prompt
  cout << endl;
  cout << ">";
  
  cin.getline(inputLine, 100);

  int i=0; // this is used to move throught the inputline charactor by charactor
  int j=0; // this is used to build the current word (word1 or word2)

  // copy characters from inputline and stop when when it hits a spaces and null
  while (inputLine[i] !=' ' && inputLine[i] != '\0'){
    // copy one charater intp word1
    word1[j] = inputLine[i];
    i++;  // more to the next character in inputLine
    j++;  // more to the next position in word1
  }

  word1[j] = '\0';

  
  if (inputLine[i] == ' '){
    i++;
  }

  // reset j
  j=0;

  // copy charactors into words2 until end
  while (inputLine[i] != '\0'){
    word2[j] = inputLine[i];
    i++;
    j++;
  }

  word2[j] = '\0';


// check wether the first word is a valid command word
if (commands.isCommand(word1)){
  return command(word1, word2);
 }
 else {
   return command("", word2);
 }
 
}

void parser::showCommands(){
  commands.showAll();
}
