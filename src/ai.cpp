#include "ai.h"
#include "board.h"
int AI::bestMove(vector<vector<char>> board, char player) {
  int val = 0;
  int emptySpaces = board.max_size() - board.size();
  cout << emptySpaces << endl;
  return val;
}
/* Player is the player currently taking a turn */
int AI::score(Board board) {
  char opponent = (board.getCurrPlayer() == 'X') ? 'O' : 'X';
  if (board.game(board, board.getCurrPlayer())) {
    return 10;
  } else if (board.game(board, opponent)) {
    return -10;
  } else
    return 0;
}

int AI::minmax(Board board) {
  if (board.getGameOver())
    return score(board);

  vector<int> moves;
  vector<int> score;

  return score[0];
}
