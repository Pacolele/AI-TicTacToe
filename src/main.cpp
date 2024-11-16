#include "board.h"

int main() {
  Board board(3);
  board.printBoard();
  bool playerOne = true;
  char player;
  int row;
  int index;
  bool gameOver = false;
  while (!gameOver) {
    string usr_inpt;
    cout << "Choose a number between 1 and 9. 1-3 first row, 4-6 2nd row, 7-9 "
            "3rd row, type 'quit' or 'exit' to stop."
         << endl;
    cout << (playerOne ? "Player one make a move: "
                       : "Player two make a move: ");
    cin >> usr_inpt;
    player = playerOne ? '0' : 'X';
    if (usr_inpt == "exit" || usr_inpt == "quit") {
      break;
    }
    if (usr_inpt == "1" || usr_inpt <= "3") {
      row = 0;
      index = stoi(usr_inpt) - 1;
    } else if (usr_inpt == "4" || usr_inpt <= "6") {
      row = 1;
      index = stoi(usr_inpt) - 4;
    } else if (usr_inpt == "7" || usr_inpt <= "9") {
      row = 2;
      index = stoi(usr_inpt) - 7;
    } else {
      continue;
    }
    if ((gameOver = board.makeMove(row, index, player))) {
      cout << (playerOne ? "Player 1 " : "Player 2") << " wins!" << endl;
      break;
    }

    board.movesMade++;
    if (board.movesMade == board.boardSize * board.boardSize) {
      gameOver = true;
      cout << "Game over it's a draw!" << endl;
    }
    playerOne = !playerOne;
    board.printBoard();
  }

  return 0;
}
