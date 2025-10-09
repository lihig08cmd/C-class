/* TicTacToe
   A simple game of TicTacToe for 2 players

   Lihi Gavrielov
   10/8/25  */

#include <iostream>
#include <string>
using namespace std;

void drawBoard (char board[3][3]);
bool checkwin(char board[3][3], char player);
bool checktie(char board[3][3]);
void resetBoard(char board[3][3]);

int main(){

  // the board
  char board[3][3];

  // keeps truck of wins
  int player1_wins = 0;
  int player2_wins = 0;

  //reset board
  resetBoard(board);
  
  // the default player is X 
  char currnetPlayer = 'X';

  while(true){
    //draw board
    drawBoard(board);

    // ask the user for a move
    string move;
    cout << "Player " << currnetPlayer << " Enter a move(example: b1): ";
    cin >> move;

    // variabels to keep track where the player wants to move
    int row, col;

    //convert letter to row
    if(move[0] == 'a'){
      row = 0;
    }
    else if (move[0] == 'b'){
      row = 1;
    }
    else if (move[0] == 'c'){
      row = 2;
    }
    else {
      cout << "Invalid row! Enter a, b or c " << endl;
      continue; }

    // convert num to col
    if(move[1] == '1') {
      col = 0;
    }
    else if(move[1]=='2'){
	col = 1;
     }
    else if (move[1] == '3'){
	col = 2;
     }
    else {
      cout << "Invalid column! Enter 1, 2 or 3" << endl;
      continue;
    }

    //check if the spot is available
    if (board[row][col] != ' '){
      cout << "Spot is taken! try again." << endl;
      continue;
    }

    //make the move
    board[row][col] = currnetPlayer;

    // check for win
    if (checkwin(board, currnetPlayer)){
      cout << currnetPlayer <<" wins!" << endl;
     

     // add win
     if (currnetPlayer == 'X'){
	player1_wins++;
     }
     else{
	player2_wins++;
     }

     //prints the score
     cout << "Scoreboard - X: " << player1_wins << " | O: " << player2_wins << endl;
     // reset the board for the new round
     resetBoard(board);
     // X always starts
     currnetPlayer = 'X';
     continue;
    }
      

    //check for tie
    if(checktie(board)){
      cout << "It's a tie!" << endl;
      //prints the score
     cout << "Scoreboard - X: " << player1_wins << " | O: " << player2_wins << endl;
     // reset the board for the new round
     resetBoard(board);
     // X always starts
     currnetPlayer = 'X';
     continue;

    }
    
    // switch players
    if (currnetPlayer == 'X'){
    currnetPlayer = 'O';
    } else{
    currnetPlayer = 'X';
    }
  }
  return 0;
}


// this functions draws the board
  void drawBoard (char board[3][3]) {
  cout << "  1 2 3" << endl;
  char rows[] = {'a', 'b', 'c'};
  // for every row
  for (int i = 0; i < 3; i++){
    // label a, b, or c and with 2 spaces
    cout << rows[i] << " ";
    //for every column 
    for (int j = 0; j < 3; j++){
      cout << board[i][j];
      // add spaces
      if (j < 2 ){
	cout << " "; }
    }
    cout << endl;
  }
}

// check if won
bool checkwin(char board[3][3], char player){
  // check every row for win
  for(int i = 0; i < 3; i++){
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player){
      // if any row is full (with the same player) win
      return true;
    }
  }

  // check every column
  for (int j=0; j<3; j++){
    // check every column 
    if (board[0][j] == player && board[1][j] == player && board[2][j] == player){
      // if any col is full win
      return true;
    }
  }
  
  // check for diagonal
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player){
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player){
    return true;
  }

  // didn't win 
  return false;
}

// Function to check for tie
bool checktie(char board[3][3]){
  for (int i = 0; i < 3; i++){
    for (int j = 0; j<3; j++){
      if (board[i][j] == ' '){
	return false;
      }
    }
  }
  // no empty spots it's a tie.
  return true;
}

// reset board function
void resetBoard(char board[3][3]){
  for (int i=0; i < 3; i++){
    for (int j=0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }

}
