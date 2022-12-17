/* 
 * Tyler Du
 * 10/17/2022
 * TicTacToe. Plays the game of TicTacToe. Should check if moves are legal and keeps track of wins.
*/

#include <iostream>
#include <cstring>

using namespace std;

// function prototypes
void printBoard(char board[3][3]);
void clearBoard(char board[3][3]);
bool checkWin (char board[3][3], char player); 
void makeMove(char board[3][3], char move);
bool full(char board[3][3]);

int main () {
  char board [3][3];
  bool playing = true;
  bool game = true;
  int xwins = 0;
  int owins = 0;
  char ans[2];
  
  while(playing) {
    clearBoard(board);
    printBoard(board);
    while(game) {
      // x moves
      makeMove(board, 'X');
      printBoard(board);
      // keeps track of wins and ties
      if (checkWin(board, 'X')) {
	cout << "X wins" << endl;
	xwins++;
	break;
      }
      if (full(board)) {
	cout << "Tie" << endl;
	break;
      }
      // o moves
      makeMove(board, 'O');
      printBoard(board);
      if (checkWin(board, 'O')) {
	cout << "O wins" << endl;
	owins++;
	break;
      }
      if (full(board)) {
	cout << "Tie" << endl;
	break;
      }
      }
    // play again
    cout << "X won " << xwins << " times." << endl;
    cout << "O won " << owins << " times." << endl;
    cout << "Play again? Type y or n" << endl;
    cin >> ans;
    if (ans[0] == 'n' || ans[0] == 'N') {
      playing = false;
    }
  }
  return 0;

  }    
// check tie
bool full (char board[3][3]) {
  for (int a = 0; a < 3; a++) {
    for (int b = 0; b < 3; b++) {
      if (board[a][b] == ' ') {
	return false;
      }
    }
  }
  return true;
}

// print board
  void printBoard(char board[3][3]) {
    cout << " 1 2 3" << endl;
    cout << "a "<<board[0][0]<<" "<<board[1][0]<<" "<< board[2][0] << endl;
    cout << "b "<<board[0][1]<<" "<<board[1][1]<<" "<< board[2][1] << endl;
    cout << "c "<<board[0][2]<<" "<<board[1][2]<<" "<<board[2][2] << endl;
  }

// clear board
void clearBoard(char board[3][3]) {
    board[0][0] = ' ';
    board[1][0] = ' ';
    board[2][0] = ' ';
    board[0][1] = ' ';
    board[1][1] = ' ';
    board[2][1] = ' ';
    board[0][2] = ' ';
    board[1][2] = ' ';
    board[2][2] = ' ';
  }
  // check win
  bool checkWin (char board[3][3], char player) {
    // checking wins for horizontal, vertical, and diagonal
    int count = 0;
    for (int a = 0; a < 3 ; a++) {
      count = 0;
      for (int b = 0; b < 3; b++) {
	if (board[a][b] == player) {
	  count++;
	}
      }
      if (count==3) {
	return true;
      }
    }
    for (int a = 0; a < 3 ; a++) {
      count = 0;
      for (int b = 0; b < 3; b++) {
	if (board[b][a] == player) {
	  count++;
	}
      }
      if(count==3){
	return true;
      }
    }
    if (board[0][0] == player) {
      if (board[1][1] == player) {
	if (board[2][2] == player) {
	  return true;
	}
      }
    }
    if (board[2][0] == player) {
      if (board[1][1] == player) {
	if (board[0][2] == player) {
	  return true;
	}
      }
    }
    return false;
  }
  void makeMove (char board[3][3], char move) {
    // player moves and invalid moves
    char input[2];
    cout << "Input a move. Type number first" << endl;
    cin >> input;
    int numletter = input[1]-64;
    int numnum = input[0]-48;
    int x;
    int y;
    if (numletter == 1 || numletter == 33) {
      y = 0;
    }
    else if (numletter == 2 || numletter == 34) {
      y = 1;
    }
    else if (numletter == 3|| numletter == 35) {
      y = 2;
    }
    else {
      cout << "Invalid move" << endl;
      makeMove(board, move);
      return;
    }
    if (numnum > 3 || numnum < 1) {
      cout << "Invalid move: " << numnum << endl;
      makeMove(board, move);
      return;
    }
    x = numnum-1;
    if (board[x][y] == ' ') {
      board[x][y] = move;
    }
    else {
      cout << "Invalid move" << endl;
      makeMove(board, move);
      return;
    }

  }
