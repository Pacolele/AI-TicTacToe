
#include "board.h"
#include <utility>
#include <vector>

void Board::printBoard() {
  cout << "*-----*-----*-----*" << endl;
  for (int row = 0; row < 3; row++) {
    // Print the content of each cell with vertical dividers
    cout << "|  " << board[row][0] << "  |  " << board[row][1] << "  |  "
         << board[row][2] << "  |" << endl;

    // Print the horizontal divider after each row, except the last one
    if (row < 2) {
      cout << "|-----|-----|-----|" << endl;
    }
  }
  cout << "*-----*-----*-----*" << endl;
}

bool Board::makeMove(int row, int col, char player) {
  if (board[row][col] != ' ') {
    cout << "Spot already taken choose another" << endl;
    return false;
  }

  board[row][col] = player;
  int increment = (player == 'X') ? 1 : -1;

  rowCount[row] += increment;
  colCount[col] += increment;

  if (row == col) {
    diagCount[0] += increment;
  } else if (row == boardSize - col - 1) {
    diagCount[1] += increment;
  }

  if (game(*this, player)) {
    return true;
  }

  return false;
}

bool Board::game(Board board, char player) {
  int target = (player == 'X') ? board.boardSize : -board.boardSize;

  for (int i = 0; i < board.boardSize; ++i) {
    if (rowCount[i] == target || colCount[i] == target) {
      return true;
    }
  }

  if (diagCount[0] == target || diagCount[1] == target) {
    return true;
  }

  return false;
}

vector<pair<int, int>> Board::getAvailableMoves() {
  vector<pair<int, int>> movesAvailable;
  for (int c = 0; c < this->boardSize; c++) {
    for (int r = 0; r < this->boardSize; r++) {
      if (this->board[r][c] == ' ') {
        movesAvailable.push_back(make_pair(r, c));
      }
    }
  }
  return movesAvailable;
}

Board Board::getBoardState(pair<int, int> cords) {
  return board[cords.first][cords.second] = currPlayer;
}

vector<vector<char>> Board::getBoard() { return this->board; }
char Board::getCurrPlayer() { return this->currPlayer; }
bool Board::getGameOver() { return this->gameOver; }

void Board::setCurrPlayer(char player) { this->currPlayer = player; }
void Board::setGameOver(bool state) { this->gameOver = state; }
