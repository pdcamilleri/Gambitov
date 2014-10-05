#include "board.h"
#include <iostream>
#include "utils.h"

Board::Board() : pawns(0) {
}

Board::~Board() {
}

void Board::loadBoardState(string position) {
  int64_t i = 1;
  for (int j = position.size() - 1; j >= 0; --j) {
    if (position[j] == 'P') {
      pawns |= i;
    }
    i <<= 1;
  }
}

bool Board::isPawn(int rank, int file) {
  return pawns & (1 << (8 * rank) << file);
}
