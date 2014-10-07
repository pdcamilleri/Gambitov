#include "board.h"
#include <iostream>
#include "utils.h"

Board::Board() : whitePawns(0), blackPawns(0), whitePieces(0), blackPieces(0),
                 whiteBishops(0), blackBishops(0), whiteKnights(0), blackKnights(0),
                 whiteRooks(0), blackRooks(0), whiteQueens(0), blackQueens(0),
                 whiteKing(0), blackKing(0) {
}

Board::~Board() {
}

void Board::loadBoardState(const string position) {
  int64_t i = 1;
  for (int j = position.size() - 1; j >= 0; --j) {
    if (position[j] == PAWN_WHITE) {
      whitePawns |= i;
      whitePieces |= i;
    } else if (position[j] == PAWN_BLACK) {
      blackPawns |= i;
      blackPieces |= i;
    } else if (position[j] == BISHOP_WHITE) {
      whiteBishops |= i;
      whitePieces |= i;
    } else if (position[j] == BISHOP_BLACK) {
      blackBishops |= i;
      blackPieces |= i;
    } else if (position[j] == KNIGHT_WHITE) {
      whiteKnights |= i;
      whitePieces |= i;
    } else if (position[j] == KNIGHT_BLACK) {
      blackKnights |= i;
      blackPieces |= i;
    } else if (position[j] == ROOK_WHITE) {
      whiteRooks |= i;
      whitePieces |= i;
    } else if (position[j] == ROOK_BLACK) {
      blackRooks |= i;
      blackPieces |= i;
    } else if (position[j] == QUEEN_WHITE) {
      whiteQueens |= i;
      whitePieces |= i;
    } else if (position[j] == QUEEN_BLACK) {
      blackQueens |= i;
      blackPieces |= i;
    } else if (position[j] == KING_WHITE) {
      whiteKing |= i;
      whitePieces |= i;
    } else if (position[j] == KING_BLACK) {
      blackKing |= i;
      blackPieces |= i;
    }
    i <<= 1;
  }
}

bool Board::isPawn(const int file, const int rank) {
  return (whitePawns | blackPawns) & rankFileBit(file, rank);
}

bool Board::isBishop(const int file, const int rank) {
  return (whiteBishops | blackBishops) & rankFileBit(file, rank);
}

bool Board::isKnight(const int file, const int rank) {
  return (whiteKnights | blackKnights) & rankFileBit(file, rank);
}

bool Board::isRook(const int file, const int rank) {
  return (whiteRooks | blackRooks) & rankFileBit(file, rank);
}

bool Board::isQueen(const int file, const int rank) {
  return (whiteQueens | blackQueens) & rankFileBit(file, rank);
}

bool Board::isKing(const int file, const int rank) {
  return (whiteKing | blackKing) & rankFileBit(file, rank);
}

bool Board::isWhite(const int file, const int rank) {
  return whitePieces & rankFileBit(file, rank);
}
