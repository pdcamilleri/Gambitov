#include "board.h"
#include "gtest/gtest.h"
#include <vector>
#include <string>

using namespace std;

TEST(TestPieceLocations, SimplePawnTest) {
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

  ASSERT_FALSE(board.isPawn(0,0));
  ASSERT_FALSE(board.isPawn(4,0));
  ASSERT_FALSE(board.isPawn(0,3));
  ASSERT_FALSE(board.isPawn(7,7));

  ASSERT_TRUE(board.isPawn(1,0));
  ASSERT_TRUE(board.isPawn(1,1));
  ASSERT_TRUE(board.isPawn(1,2));
  ASSERT_TRUE(board.isPawn(1,3));
  ASSERT_TRUE(board.isPawn(1,4));
  ASSERT_TRUE(board.isPawn(1,5));
  ASSERT_TRUE(board.isPawn(1,6));
  ASSERT_TRUE(board.isPawn(1,7));
}
