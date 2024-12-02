#ifndef BOARD_H
#define BOARD_H

#include "string"
#include <iostream>
#include <vector>
using namespace std;

class Board {
public:
  Board(int size) : boardSize(size) {
    board = vector<vector<char>>(boardSize, vector<char>(boardSize, ' '));
    rowCount = vector<int>(boardSize, 0);
    colCount = vector<int>(boardSize, 0);
    diagCount = vector<int>(2, 0);
  };
  ~Board() {};
  void printBoard();
  bool makeMove(int row, int col, char player);
  bool computerMove(int row, int col);
  int movesMade = 0;
  int boardSize;

private:
  vector<vector<char>> board;
  vector<int> rowCount;
  vector<int> colCount;
  vector<int> diagCount;
  // string board[boardSize][boardSize];
};
#endif
