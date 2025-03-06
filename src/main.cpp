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
  char human = 'X', bot = 'O';
  board.setHumanChar(human);
  board.setBotChar(bot);

  // Game variables
  bool humanTurn = humanStarts;
  bool gameOver = false;
  pair<int, int> move;
  cout << "You are playing as: " << human << endl;
  while (!gameOver) {
    if (humanTurn) {
      board.setCurrPlayer(human);
      string usr_inpt;
      cout
          << "Choose a number between 1 and 9. 1-3 first row, 4-6 2nd row, 7-9 "
             "3rd row"
          << endl;
      // cin >> usr_inpt;
      int pos;

      try {
        while (true) {
          cin >> usr_inpt;
          if ((pos = stoi(usr_inpt)) < 1 || pos > 9)
            continue;
          move.first = (pos - 1) / 3;
          move.second = (pos - 1) % 3;
          if (board.spotEmpty(move)) {
            break;
          }
        }
        if ((gameOver = board.makeMove(move, human))) {
          cout << "You win!" << endl;
          board.printBoard();
          break;
        }
      } catch (exception &e) {
        cout << "Invalid input, enter a number between 1-9" << endl;
        continue;
      }

    } else {
      board.setCurrPlayer(bot);
      cout << "opponents turn... getting best moves..." << endl;
      ai.minmax(board.getBoard(), true);

      cout << "Best possible move: " << ai.choice.first << ", "
           << ai.choice.second << endl;
      cout << "Total iterations: " << ai.iterations << endl;
      ai.iterations = 0;
      if ((gameOver = board.makeMove(ai.choice, bot))) {
        cout << "You lose!" << endl;
        board.printBoard();
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
