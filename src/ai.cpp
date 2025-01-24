#include "ai.h"
#include "board.h"
#include <algorithm>

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

  vector<pair<int, int>> moves;
  vector<int> score;
  vector<pair<int, int>> movesAvailable = board.getAvailableMoves();

  for (auto move : movesAvailable) {
    Board possibleBoard = board.getBoardState(move);
    score.push_back(minmax(possibleBoard));
    moves.push_back(move);
  }

  if (board.getCurrPlayer() == 'X') {
    int max_score_index =
        max_element(score.begin(), score.end()) - score.begin();

    choice = moves[max_score_index];
    return score[max_score_index];
  } else {
    int min_score_index =
        min_element(score.begin(), score.end()) - score.begin();

    choice = moves[min_score_index];
    return score[min_score_index];
  }
  return score[0];
}
