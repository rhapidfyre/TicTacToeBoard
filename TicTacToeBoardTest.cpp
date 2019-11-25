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

// Does toggling the turn from X to O work
TEST(TicTacToeBoard, toggleTurn1) {
  TicTacToeBoard board;
  ASSERT_EQ(board.toggleTurn(), O);
}

// Can the turn be toggled back to X
TEST(TicTacToeBoard, toggleTurn2) {
  TicTacToeBoard board;
  board.toggleTurn();
  ASSERT_EQ(board.toggleTurn(), X);
}

// Place the first piece
TEST(TicTacToeBoard, placePiece1) {
  TicTacToeBoard board;
  ASSERT_EQ(board.placePiece(0,0), X);
}

// Pieces out of bounds should return Invalid
TEST(TicTacToeBoard, placePieceOut) {
  TicTacToeBoard board;
  ASSERT_EQ(board.placePiece(-1,8), Invalid);
  ASSERT_EQ(board.placePiece(0,-1), Invalid);
  ASSERT_EQ(board.placePiece(-1,-1), Invalid);
  ASSERT_EQ(board.placePiece(8,-1), Invalid);
}

// If piece is placed where one already is,
// test should return that piece but not toggle turns
TEST(TicTacToeBoard, placePieceRepeat) {
  TicTacToeBoard board;
  board.placePiece(1,1); // X places
  ASSERT_EQ(board.placePiece(1,1), O); // O places
  ASSERT_EQ(board.toggleTurn(), X); // If turn togs to X it was O's turn still
}





