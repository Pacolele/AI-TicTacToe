#include "ai.h"
#include "board.h"
#include <algorithm>
#include <iterator>
#include <numeric>

/* Player is the player currently taking a turn */
int AI::score(Board board) {
  // cout << "Current player in score function: " << board.getCurrPlayer() <<
  // endl;
  char opponent = (board.getCurrPlayer() == 'O') ? 'X' : 'O';
  if (board.game(board, board.getCurrPlayer())) {
    return 10;
  } else if (board.game(board, opponent)) {
    return -10;
  } else
    return 0;
}

int AI::minmax(Board board, bool isRoot = false) {
  if (board.getGameOver())
    return score(board);

  vector<pair<int, int>> movesAvailable = board.getAvailableMoves();
  if (movesAvailable.empty()) {
    return score(board);
  }
  // cout << "Length of moves available: " << movesAvailable.size() << endl;
  if (isRoot) {
    vector<pair<int, int>> moves;
    vector<int> total;
    for (auto move : movesAvailable) {
      Board possibleBoard = board.getBoardState(move);
      cout << "Possible board: " << endl;
      possibleBoard.printBoard();
      if (possibleBoard.game(possibleBoard, board.getBotChar())) {
        cout << "HEEEELLOOO ITS OVER: " << endl;
        choice = move;
        return score(possibleBoard);
      }
      int totalSum = minmax(possibleBoard);
      total.push_back(totalSum);
      moves.push_back(move);
    }
    int bestIndex = 0;
    cout << board.getCurrPlayer() << endl;

    if (board.getCurrPlayer() == 'O') {
      cout << "Getting highest amount" << endl;
      bestIndex =
          distance(total.begin(), max_element(total.begin(), total.end()));

    } else {
      bestIndex =
          distance(total.begin(), min_element(total.begin(), total.end()));
    }
    cout << bestIndex << endl;
    choice = moves[bestIndex];
    for (auto s : total) {
      cout << s << endl;
    }
    for (auto move : moves) {
      cout << move.first << ":" << move.second << endl;
    }
    return total[bestIndex];
  }

  int branchSum = 0;
  for (auto move : movesAvailable) {
    Board newBoard = board.getBoardState(move);
    branchSum += minmax(newBoard);
  }
  iterations += 1;

  return branchSum;
}
