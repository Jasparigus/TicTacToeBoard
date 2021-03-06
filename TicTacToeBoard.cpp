#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if (turn == X)
  {
    turn = O;
  }
  
  else
  {
    turn = X;
  }
  
  return turn;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  //Check bounds
  if (row < 0 || column < 0 || row > BOARDSIZE - 1 || column >  BOARDSIZE - 1) {
     return Invalid; 
  }
  
  //Check already existing piece
  if (board[row][column] != ' ') {
    return board[row][column];
  }
  
  // Space must be open, set the value
  board[row][column] = turn;
  
  //Toggle turns
  toggleTurn();
  
  //Return placed piece
  return getPiece(row, column);
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  //Check bounds
  if (row < 0 || column < 0 || row > BOARDSIZE - 1 || column > BOARDSIZE - 1) {
     return Invalid; 
  }
  
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  bool over = true;
  Piece winner = Invalid;
  
  //Game might not be over if there is a blank
  for(int i=0; i<BOARDSIZE; i++)
  {
    for(int j=0; j<BOARDSIZE; j++)
    {
      if (board[i][j] == Blank)
      {
        over = false;
      }
    }
  }
  
  //Check vertical rows
  for(int i=0; i < BOARDSIZE; i++)
  {
    if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
    {
      winner = board[i][0];
    }
  }
  
  //Check horizontal rows
  for(int i=0; i < BOARDSIZE; i++)
  {
    if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
    {
      winner = board[0][i];
    }
  }
  
  //Check diagonals
  if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
  {
    winner = board[0][0];
  }
  
  if (board[2][0] == board[1][1] && board[2][2] == board[0][2])
  {
    winner = board[2][0];
  }
  
  
  // Make sure matching pieces are not filler pieces
  if (winner == X || winner == O)
  {
    return winner;
  }
  
  //Then the game might not be over
  if (!over)
  {
    return Invalid;
  }
  
  else 
  {
    return Blank;
  }
  
}
