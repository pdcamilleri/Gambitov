//http://www.royvanrijn.com/blog/2011/02/unit-testing-a-chess-engine/

#include "gambitov.h"
#include "gtest/gtest.h"

TEST(TestQueenCheckmate, KingQueenCheckmate) {
  Gambitov gambitov;
  gambitov.think();
  EXPECT_EQ(2, gambitov.think());
}
