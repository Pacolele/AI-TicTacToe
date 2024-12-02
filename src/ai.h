#ifndef AI_H
#define AI_H
/*
 * Includes
 */
#include "string"
#include <vector>
using namespace std;
/****************/
class AI {
  AI() {}
  ~AI() {}

  int bestMove(vector<vector<char>> board, char player);
};

#endif
