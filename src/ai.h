#ifndef AI_H
#define AI_H
/*
 * Includes
 */
#include "board.h"
#include "string"
#include <iostream>
#include <vector>
using namespace std;
/****************/
class AI {
  AI() {}
  ~AI() {}

  int bestMove(vector<vector<char>> board, char player);
  int score(Board board);
  int minmax(Board board);
};
#endif
