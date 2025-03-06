
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

bool Board::makeMove(pair<int, int> move, char player) {
  if (board[move.first][move.second] != ' ') {
    cout << "Spot already taken choose another" << endl;
    return false;
  }

  board[move.first][move.second] = player;
  int increment = (player == 'X') ? 1 : -1;

  rowCount[move.first] += increment;
  colCount[move.second] += increment;

  if (move.first == move.second) {
    diagCount[0] += increment;
    if (move.first == 1 && move.second == 1) { // We are in the middle position
      diagCount[1] += increment;
    }
  } else if (move.first == boardSize - move.second - 1) {
    diagCount[1] += increment;
  }

  if (game(*this, player)) {
    return true;
  }

  return false;
}

bool Board::spotEmpty(pair<int, int> move) {
  if (board[move.first][move.second] == ' ') {
    cout << "Spot empty" << endl;
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
  for (int r = 0; r < this->boardSize; r++) {
    for (int c = 0; c < this->boardSize; c++) {
      if (this->board[r][c] == ' ') {
        movesAvailable.push_back(make_pair(r, c));
      }
    }
  }
  return movesAvailable;
}

Board Board::getBoardState(pair<int, int> cords) {
  Board newBoard(*this);
  newBoard.board[cords.first][cords.second] = currPlayer;
  int increment = (currPlayer == 'X') ? 1 : -1;
  newBoard.rowCount[cords.first] += increment;
  newBoard.colCount[cords.second] += increment;
  if (cords.first == cords.second) {
    newBoard.diagCount[0] += increment;
    if (cords.first == 1 &&
        cords.second == 1) { // We are in the middle position
      newBoard.diagCount[1] += increment;
    }
  }
  if (cords.first == boardSize - cords.second - 1) {
    newBoard.diagCount[1] += increment;
  }
  newBoard.currPlayer = (currPlayer == 'X') ? 'O' : 'X';
  return newBoard;
}

Board Board::getBoard() { return *this; }
char Board::getCurrPlayer() { return this->currPlayer; }
bool Board::getGameOver() { return this->gameOver; }
char Board::getHumanChar() { return this->human; }
char Board::getBotChar() { return this->bot; }
void Board::setCurrPlayer(char player) { this->currPlayer = player; }
void Board::setGameOver(bool state) { this->gameOver = state; }
void Board::setHumanChar(char c) { this->human = c; }
void Board::setBotChar(char c) { this->bot = c; }
