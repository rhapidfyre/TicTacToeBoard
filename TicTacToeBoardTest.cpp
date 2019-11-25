/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

// Tests each enum for validity
TEST(TicTacToeBoard, Piece) {
  ASSERT_EQ(X, 'X');
  ASSERT_EQ(O, 'O');
  ASSERT_EQ(Invalid, '?');
  ASSERT_EQ(Blank, ' ');
}

// Does toggling the turn to X work
TEST(TicTacToeBoard, toggleTurn1) {
  TicTacToeBoard board;
  ASSERT_EQ(board.toggleTurn(), X);
}

// Can the turn be toggled to O
TEST(TicTacToeBoard, toggleTurn2) {
  TicTacToeBoard board;
  board.toggleTurn();
  ASSERT_EQ(board.toggleTurn(), O);
}

