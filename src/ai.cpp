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

  vector<pair<int, int>> movesAvailable = board.getAvailableMoves();
  if (movesAvailable.empty()) {
    return score(board);
  }

  vector<pair<int, int>> moves;
  vector<int> score;

  for (auto move : movesAvailable) {
    Board possibleBoard = board.getBoardState(move);
    int currentScore = minmax(possibleBoard);
    score.push_back(currentScore);
    moves.push_back(move);
  }

  if (board.getCurrPlayer() == 'X') {
    // Maximizing player: choose the move with the maximum score.
    auto max_it = max_element(score.begin(), score.end());
    int max_index = distance(score.begin(), max_it);
    choice = moves[max_index];
    return score[max_index];
  } else {
    // Minimizing player: choose the move with the minimum score.
    auto min_it = min_element(score.begin(), score.end());
    int min_index = distance(score.begin(), min_it);
    choice = moves[min_index];
    return score[min_index];
  }
  return score[0];
}
