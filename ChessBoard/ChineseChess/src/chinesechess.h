/*
 *
 */

#ifndef _CHINESE_CHESS
#define _CHINESE_CHESS

#include "chessboard.h"


using namespace std;

class ChineseChess
{
public:
	ChineseChess();
	~ChineseChess();
	
	// check game status
	bool isGameOver() { return this->chessBoard.isGameOver(); };
	
	// reset the chess and play again
	void reset();
	
	// print the chess board with peices
	void printChessBoard();

	// move one step according to a string command.
	// return: false -  the move is invalid
	//         true  -  the move is success
	bool move(const string &command);
	
	void setNotationFile(const string &file) { this->notationFile = file; };
	
private:
	
	void saveCommandToNotationFile(const string &command);
	
private:
	
	ChineseChessBoard	chessBoard;
	
	string notationFile;		///< notation  file to record the game
};


#endif

