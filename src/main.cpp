#include "ai.h"
#include "board.h"
#include <random>
int main() {
  // Setup board
  Board board(3);
  board.printBoard();
  // Bot setup
  AI ai;
  // Setup random for gamestart
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dist(0, 1);
  bool humanStarts = (dist(gen) == 0);
  char human = humanStarts ? 'O' : 'X', bot = humanStarts ? 'X' : 'O';
  // Game variables
  bool humanTurn = humanStarts;
  bool gameOver = false;
  pair<int, int> move;
  cout << "You are playing as: " << human << endl;
  while (!gameOver) {
    if (humanTurn) {
      string usr_inpt;
      cout
          << "Choose a number between 1 and 9. 1-3 first row, 4-6 2nd row, 7-9 "
             "3rd row, type 'quit' or 'exit' to stop."
          << endl;
      cin >> usr_inpt;
      int pos;
      if (usr_inpt == "exit" || usr_inpt == "quit") {
        break;
      }
      try {
        if ((pos = stoi(usr_inpt)) < 1 || pos > 9)
          continue;
        move.first = (pos - 1) / 3;
        move.second = (pos - 1) % 3;
        cout << move.first << ", " << move.second << endl;
        if ((gameOver = board.makeMove(move, human))) {
          cout << "You win!" << endl;
          break;
        }
      } catch (exception &e) {
        cout << "Invalid input, enter a number between 1-9" << endl;
        continue;
      }

    } else {
      cout << "opponents turn... getting best moves..." << endl;
      ai.minmax(board.getBoard());
      cout << "Best possible move: " << ai.choice.first << ", "
           << ai.choice.second << endl;
      if ((gameOver = board.makeMove(ai.choice, bot))) {
        cout << "You win!" << endl;
        break;
      }
    }

    board.movesMade++;
    if (board.movesMade == board.boardSize * board.boardSize) {
      gameOver = true;
      cout << "Game over it's a draw!" << endl;
    }
    humanTurn = !humanTurn;
    board.printBoard();
  }

  return 0;
}
