#include "board.h"
#include <iostream>
#include "utils.h"

Board::Board() : whitePawns(0), blackPawns(0), whitePieces(0), blackPieces(0) {
}

Board::~Board() {
}

void Board::loadBoardState(string position) {
  int64_t i = 1;
  for (int j = position.size() - 1; j >= 0; --j) {
    if (position[j] == PAWN_WHITE) {
      whitePawns |= i;
      whitePieces |= i;
    } else if (position[j] == PAWN_BLACK) {
      blackPawns |= i;
      blackPieces |= i;
    }
    i <<= 1;
  }
}

bool Board::isPawn(int rank, int file) {
  return (whitePawns | blackPawns) & rankFileBit(rank, file);
}

bool Board::isWhite(int rank, int file) {
  return whitePieces & rankFileBit(rank, file);
}
