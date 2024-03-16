/*
 *
 */

#ifndef _CHESS_BOARD_H
#define _CHESS_BOARD_H


#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "piece.h"


using namespace std;

class ChessNotation;

class ChineseChessBoard
{
public:
	ChineseChessBoard();
	~ChineseChessBoard();
	
	void createChessBoard(char matrix[][9]);
	
	bool isGameOver() { return this->gameOver; };
	
	void reset();				///< reset chess board to initial stage and play again.
	
	// print the chess board with peices
	void printChessBoard();
	
	// move one step according to a chess notation.
	// return: false -  the move is invalid
	//         true  -  the move is success
	bool move(const ChessNotation &notation);
	
private:
	
	void clearChessBoard();					///< clear memory used by this board
	void backupMatrix(char matrix[][9]); 	///< backup matrix. Can use the default matrix to reset the chess board later.
	
private:
	
	bool	gameOver;						///< true for game over
	
	vector<Piece *> m_capturedPieceList[2];		///< pieces captured by the players
	
	vector<Piece *> m_pieceList;		///< list of pieces
	
	Piece *board[10][9];				///< chess board matrix

	char defaultMatrix[10][9];			///< default board matrix
};

// ChessNotation handle player's command
class ChessNotation
{
public:
	ChessNotation() {};
	~ChessNotation() {};
	
	bool parse(const string &command);
	
	void dump();	///< print notation for debug
	
public:
	
	char  pieceName;	///< piece name
	int   col;			///< column number of the piece
	PieceDirection direction;	///< direction for how to move the piece
	int   step;			///< how many steps to move or the col number for the piece to move to
	ChessPlayer player; ///< chess player
};

#endif
