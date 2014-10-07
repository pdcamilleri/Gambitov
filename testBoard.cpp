#include "board.h"
#include "gtest/gtest.h"
#include <vector>
#include <string>
#include "utils.h"

using namespace std;

TEST(TestPieceLocations, WhitePawnTest) {
  Board board;
  string position(
    "________"
    "________"
    "________"
    "________"
    "________"
    "________"
    "PPPPPPPP"
    "________"
  );

  board.loadBoardState(position);

  ASSERT_TRUE(board.isPawn(0,1));
  ASSERT_TRUE(board.isPawn(1,1));
  ASSERT_TRUE(board.isPawn(2,1));
  ASSERT_TRUE(board.isPawn(3,1));
  ASSERT_TRUE(board.isPawn(4,1));
  ASSERT_TRUE(board.isPawn(5,1));
  ASSERT_TRUE(board.isPawn(6,1));
  ASSERT_TRUE(board.isPawn(7,1));

  ASSERT_TRUE(board.isWhite(0,1));
  ASSERT_TRUE(board.isWhite(1,1));
  ASSERT_TRUE(board.isWhite(2,1));
  ASSERT_TRUE(board.isWhite(3,1));
  ASSERT_TRUE(board.isWhite(4,1));
  ASSERT_TRUE(board.isWhite(5,1));
  ASSERT_TRUE(board.isWhite(6,1));
  ASSERT_TRUE(board.isWhite(7,1));

  ASSERT_FALSE(board.isPawn(0,0));
  ASSERT_FALSE(board.isPawn(0,4));
  ASSERT_FALSE(board.isPawn(3,0));
  ASSERT_FALSE(board.isPawn(7,7));

}



TEST(TestPieceLocations, BlackPawnTest) {
  Board board;
  string position(
    "________"
    "pppppppp"
    "________"
    "________"
    "________"
    "________"
    "________"
    "________"
  );

  board.loadBoardState(position);
  
  ASSERT_TRUE(board.isPawn(0,6));
  ASSERT_TRUE(board.isPawn(1,6));
  ASSERT_TRUE(board.isPawn(2,6));
  ASSERT_TRUE(board.isPawn(3,6));
  ASSERT_TRUE(board.isPawn(4,6));
  ASSERT_TRUE(board.isPawn(5,6));
  ASSERT_TRUE(board.isPawn(6,6));
  ASSERT_TRUE(board.isPawn(7,6));

  ASSERT_FALSE(board.isWhite(0,6));
  ASSERT_FALSE(board.isWhite(1,6));
  ASSERT_FALSE(board.isWhite(2,6));
  ASSERT_FALSE(board.isWhite(3,6));
  ASSERT_FALSE(board.isWhite(4,6));
  ASSERT_FALSE(board.isWhite(5,6));
  ASSERT_FALSE(board.isWhite(6,6));
  ASSERT_FALSE(board.isWhite(7,6));

  ASSERT_FALSE(board.isPawn(0,0));
  ASSERT_FALSE(board.isPawn(0,4));
  ASSERT_FALSE(board.isPawn(3,0));
  ASSERT_FALSE(board.isPawn(7,7));

}


TEST(TestPieceLocations, WhiteBishopTest) {
  Board board;
  string position(
    "B______B"
    "________"
    "________"
    "________"
    "________"
    "____B___"
    "________"
    "B_______"
  );

  board.loadBoardState(position);
  
  ASSERT_TRUE(board.isBishop(0,0));
  ASSERT_TRUE(board.isBishop(4,2));
  ASSERT_TRUE(board.isBishop(0,7));
  ASSERT_TRUE(board.isBishop(7,7));

  ASSERT_TRUE(board.isWhite(0,0));
  ASSERT_TRUE(board.isWhite(4,2));
  ASSERT_TRUE(board.isWhite(0,7));
  ASSERT_TRUE(board.isWhite(7,7));

}

TEST(TestPieceLocations, BlackBishopTest) {
  Board board;
  string position(
    "b______b"
    "________"
    "________"
    "________"
    "________"
    "____B___"
    "________"
    "b_______"
  );

  board.loadBoardState(position);
  
  ASSERT_TRUE(board.isBishop(0,0));
  ASSERT_TRUE(board.isBishop(4,2));
  ASSERT_TRUE(board.isBishop(0,7));
  ASSERT_TRUE(board.isBishop(7,7));

  ASSERT_FALSE(board.isWhite(0,0));
  ASSERT_FALSE(board.isWhite(0,7));
  ASSERT_FALSE(board.isWhite(7,7));
  ASSERT_TRUE(board.isWhite(4,2));

}

TEST(TestPieceLocations, WhiteKnightTest) {
  Board board;
  string position(
    "________"
    "_N______"
    "_____N__"
    "________"
    "________"
    "_N______"
    "_______N"
    "________"
  );

  board.loadBoardState(position);
  
  ASSERT_TRUE(board.isKnight(1,6));
  ASSERT_TRUE(board.isKnight(1,2));
  ASSERT_TRUE(board.isKnight(7,1));
  ASSERT_TRUE(board.isKnight(5,5));

  ASSERT_TRUE(board.isWhite(1,6));
  ASSERT_TRUE(board.isWhite(1,2));
  ASSERT_TRUE(board.isWhite(7,1));
  ASSERT_TRUE(board.isWhite(5,5));

}

TEST(TestPieceLocations, BlackKnightTest) {
  Board board;
  string position(
    "________"
    "_______n"
    "________"
    "________"
    "_n______"
    "________"
    "_____n__"
    "________"
  );

  board.loadBoardState(position);
  
  ASSERT_TRUE(board.isKnight(1,3));
  ASSERT_TRUE(board.isKnight(5,1));
  ASSERT_TRUE(board.isKnight(7,6));

  ASSERT_FALSE(board.isWhite(1,3));
  ASSERT_FALSE(board.isWhite(5,1));
  ASSERT_FALSE(board.isWhite(7,6));

}


TEST(TestPieceLocations, WhiteRookTest) {
  Board board;
  string position(
    "________"
    "R_____R_"
    "________"
    "________"
    "______R_"
    "________"
    "__r_____"
    "________"
  );

  board.loadBoardState(position);
  
  ASSERT_TRUE(board.isRook(0,6));
  ASSERT_TRUE(board.isRook(6,6));
  ASSERT_TRUE(board.isRook(6,3));
  ASSERT_TRUE(board.isRook(2,1));

  ASSERT_TRUE(board.isWhite(0,6));
  ASSERT_TRUE(board.isWhite(6,6));
  ASSERT_TRUE(board.isWhite(6,3));
  ASSERT_FALSE(board.isWhite(2,1));

}

TEST(TestPieceLocations, BlackRookTest) {
  Board board;
  string position(
    "________"
    "___r____"
    "________"
    "________"
    "_r______"
    "____r___"
    "________"
    "____r___"
  );

  board.loadBoardState(position);
  
  ASSERT_TRUE(board.isRook(1,3));
  ASSERT_TRUE(board.isRook(3,6));
  ASSERT_TRUE(board.isRook(4,2));
  ASSERT_TRUE(board.isRook(4,0));

  ASSERT_FALSE(board.isWhite(1,3));
  ASSERT_FALSE(board.isWhite(3,6));
  ASSERT_FALSE(board.isWhite(4,2));
  ASSERT_FALSE(board.isWhite(4,0));

}

TEST(TestPieceLocations, WhiteQueenTest) {
  Board board;
  string position(
    "________"
    "___Q____"
    "________"
    "_____Q__"
    "________"
    "_Q______"
    "________"
    "________"
  );

  board.loadBoardState(position);
  
  ASSERT_TRUE(board.isQueen(1,2));
  ASSERT_TRUE(board.isQueen(3,6));
  ASSERT_TRUE(board.isQueen(5,4));

  ASSERT_TRUE(board.isWhite(1,2));
  ASSERT_TRUE(board.isWhite(3,6));
  ASSERT_TRUE(board.isWhite(5,4));

}

TEST(TestPieceLocations, BlackQueenTest) {
  Board board;
  string position(
    "________"
    "___q____"
    "________"
    "________"
    "______q_"
    "________"
    "__q_____"
    "________"
  );

  board.loadBoardState(position);
  
  ASSERT_TRUE(board.isQueen(2,1));
  ASSERT_TRUE(board.isQueen(6,3));
  ASSERT_TRUE(board.isQueen(3,6));

  ASSERT_FALSE(board.isWhite(2,1));
  ASSERT_FALSE(board.isWhite(6,3));
  ASSERT_FALSE(board.isWhite(3,6));

}

TEST(TestPieceLocations, WhiteKingTest) {
  Board board;
  string position(
    "________"
    "________"
    "________"
    "___K____"
    "________"
    "________"
    "________"
    "________"
  );

  board.loadBoardState(position);
  
  ASSERT_TRUE(board.isKing(3,4));

  ASSERT_TRUE(board.isWhite(3,4));

}

TEST(TestPieceLocations, BlackKingTest) {
  Board board;
  string position(
    "________"
    "________"
    "________"
    "________"
    "____k___"
    "________"
    "________"
    "________"
  );

  board.loadBoardState(position);
  
  ASSERT_TRUE(board.isKing(4,3));

  ASSERT_FALSE(board.isWhite(4,3));

}

