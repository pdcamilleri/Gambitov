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

  ASSERT_TRUE(board.isPawn(1,0));
  ASSERT_TRUE(board.isPawn(1,1));
  ASSERT_TRUE(board.isPawn(1,2));
  ASSERT_TRUE(board.isPawn(1,3));
  ASSERT_TRUE(board.isPawn(1,4));
  ASSERT_TRUE(board.isPawn(1,5));
  ASSERT_TRUE(board.isPawn(1,6));
  ASSERT_TRUE(board.isPawn(1,7));

  ASSERT_TRUE(board.isWhite(1,0));
  ASSERT_TRUE(board.isWhite(1,1));
  ASSERT_TRUE(board.isWhite(1,2));
  ASSERT_TRUE(board.isWhite(1,3));
  ASSERT_TRUE(board.isWhite(1,4));
  ASSERT_TRUE(board.isWhite(1,5));
  ASSERT_TRUE(board.isWhite(1,6));
  ASSERT_TRUE(board.isWhite(1,7));

  ASSERT_FALSE(board.isPawn(0,0));
  ASSERT_FALSE(board.isPawn(4,0));
  ASSERT_FALSE(board.isPawn(0,3));
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
    "--------"
    "________"
  );

  board.loadBoardState(position);
  
  ASSERT_TRUE(board.isPawn(6,0));
  ASSERT_TRUE(board.isPawn(6,1));
  ASSERT_TRUE(board.isPawn(6,2));
  ASSERT_TRUE(board.isPawn(6,3));
  ASSERT_TRUE(board.isPawn(6,4));
  ASSERT_TRUE(board.isPawn(6,5));
  ASSERT_TRUE(board.isPawn(6,6));
  ASSERT_TRUE(board.isPawn(6,7));

  ASSERT_FALSE(board.isWhite(6,0));
  ASSERT_FALSE(board.isWhite(6,1));
  ASSERT_FALSE(board.isWhite(6,2));
  ASSERT_FALSE(board.isWhite(6,3));
  ASSERT_FALSE(board.isWhite(6,4));
  ASSERT_FALSE(board.isWhite(6,5));
  ASSERT_FALSE(board.isWhite(6,6));
  ASSERT_FALSE(board.isWhite(6,7));

  ASSERT_FALSE(board.isPawn(0,0));
  ASSERT_FALSE(board.isPawn(4,0));
  ASSERT_FALSE(board.isPawn(0,3));
  ASSERT_FALSE(board.isPawn(7,7));

}


