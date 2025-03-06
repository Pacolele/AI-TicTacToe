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
public:
  AI() {}
  ~AI() {}
  int score(Board board);
  int minmax(Board board, bool isRoot);
  pair<int, int> choice;
  int iterations;
};
#endif
