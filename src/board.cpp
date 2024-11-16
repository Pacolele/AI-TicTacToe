
#include "board.h"
#include <string>

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

  if (abs(rowCount[row]) == boardSize || abs(colCount[col]) == boardSize ||
      abs(diagCount[0]) == boardSize || abs(diagCount[1]) == boardSize) {
    return true;
  }

  return false;
}
