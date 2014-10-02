//http://www.royvanrijn.com/blog/2011/02/unit-testing-a-chess-engine/

#include "gambitov.h"
#include "gtest/gtest.h"
#include <vector>
#include <string>

TEST(TestBishopMovement, SimpleBishopMove) {
  Gambitov gambitov;
  string position(
    "b_______"
    "________"
    "________"
    "________"
    "________"
    "________"
    "________"
    "________"
  );

  gambitov.loadBoardState(position);
  vector<int> expectedMoves;
  expectedMoves.push_back(1);
  EXPECT_EQ(expectedMoves, gambitov.getAllMoves());

}

TEST(TestRookMovement, SimpleRookMove) {
  Gambitov gambitov;
  gambitov.think();
  EXPECT_EQ(2, gambitov.think());
}
