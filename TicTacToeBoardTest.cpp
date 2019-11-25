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
TEST(TicTacToeBoard, buildBoard) {
  TicTacToeBoard board;
  ASSERT_EQ(board.getPiece(0,0), Blank);
  ASSERT_EQ(board.getPiece(0,1), Blank);
  ASSERT_EQ(board.getPiece(0,2), Blank);
  ASSERT_EQ(board.getPiece(1,0), Blank);
  ASSERT_EQ(board.getPiece(1,1), Blank);
  ASSERT_EQ(board.getPiece(1,2), Blank);
  ASSERT_EQ(board.getPiece(2,0), Blank);
  ASSERT_EQ(board.getPiece(2,1), Blank);
  ASSERT_EQ(board.getPiece(2,2), Blank);
}

TEST(TicTacToeBoard, checkEnums) {
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
  board.placePiece(1,1); // Place X in Center
  ASSERT_EQ(board.placePiece(1,1), X); // Place O center, return X
  ASSERT_EQ(board.toggleTurn(), X); // If turn togs to X it was O's turn still
}

// Do pieces return properly
TEST(TicTacToeBoard, getPieces) {
  TicTacToeBoard board;
  board.placePiece(0,0); // Places X in 0 0
  board.placePiece(0,1); // Places O in 0 1
  ASSERT_EQ(board.getPiece(0,1), O); // is 0 1 O?
}

TEST(TicTacToeBoard, horizontalWin) {
  TicTacToeBoard board;
  board.placePiece(0,0);
  board.placePiece(0,1);
  board.placePiece(1,0);
  board.placePiece(1,1);
  board.placePiece(2,0);
  ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoard, verticalWin) {
  TicTacToeBoard board;
  board.placePiece(0,0);
  board.placePiece(1,0);
  board.placePiece(0,1);
  board.placePiece(1,1);
  board.placePiece(0,2);
  ASSERT_EQ(board.getWinner(), X); 
}

TEST(TicTacToeBoard, diagonalWinLeft) {
  TicTacToeBoard board;
  board.placePiece(0,0);
  board.placePiece(1,0);
  board.placePiece(1,1);
  board.placePiece(2,0);
  board.placePiece(2,2);
  ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoard, diagonalWinRight) {
  TicTacToeBoard board;
  board.placePiece(2,0);
  board.placePiece(1,0);
  board.placePiece(1,1);
  board.placePiece(0,1);
  board.placePiece(0,2);
  ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoard, playAfterWin) { 
  TicTacToeBoard board;
  board.placePiece(2,0);
  board.placePiece(1,0);
  board.placePiece(1,1);
  board.placePiece(0,1);
  board.placePiece(0,2);
  board.getWinner();
  ASSERT_EQ(board.placePiece(2,2), Invalid);
}

TEST(TicTacToeBoard, notFinished) {
  TicTacToeBoard board;
  board.placePiece(0,0);
  ASSERT_EQ(board.getWinner(), Invalid);
}

TEST(TicTacToeBoard, catsGame) {
  TicTacToeBoard board;
  board.placePiece(0,0);
  board.placePiece(1,1);
  board.placePiece(2,0);
  board.placePiece(1,0);
  board.placePiece(1,2);
  board.placePiece(0,2);
  board.placePiece(2,2);
  board.placePiece(2,1);
  board.placePiece(0,1);
  for (unsigned i = 0; i < 3; i++) {
    for (unsigned j = 0; i < 3; i++) {
      // Ensure the spot is an X or an O
      ASSERT_NE(board.getPiece(i,j), Invalid);
      ASSERT_NE(board.getPiece(i,j), Blank);
    }
  }
  ASSERT_EQ(board.getWinner(), Blank);
}

