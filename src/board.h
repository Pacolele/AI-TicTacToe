#ifndef BOARD_H
#define BOARD_H

#include "string"
#include <cstdlib>
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
    currPlayer = (rand() % 2 == 0) ? 'X' : '=';
    gameOver = false;
  };
  ~Board() {};
  void printBoard();
  bool spotEmpty(pair<int, int> move);
  bool makeMove(pair<int, int> move, char player);
  bool game(Board board, char player);
  vector<pair<int, int>> getAvailableMoves();
  Board getBoardState(pair<int, int> cords);
  int movesMade = 0;
  int boardSize;
  /* Getters */
  Board getBoard();
  char getCurrPlayer();
  bool getGameOver();
  char getHumanChar();
  char getBotChar();
  /* Setters */
  void setCurrPlayer(char player);
  void setGameOver(bool state);
  void setHumanChar(char c);
  void setBotChar(char c);

private:
  vector<vector<char>> board;
  vector<int> rowCount;
  vector<int> colCount;
  vector<int> diagCount;
  char currPlayer;
  bool gameOver;
  char human;
  char bot;
};
#endif
