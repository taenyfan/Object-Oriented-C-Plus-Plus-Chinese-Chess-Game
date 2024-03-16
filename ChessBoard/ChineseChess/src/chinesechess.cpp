/**
*
*/

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

#include "chinesechess.h"


ChineseChess::ChineseChess()
{
	this->notationFile = "notation.txt";
	this->reset();
}

ChineseChess::~ChineseChess()
{
	
}

void ChineseChess::reset()
{
	this->chessBoard.reset();
}

void ChineseChess::printChessBoard()
{
	this->chessBoard.printChessBoard();
}

bool ChineseChess::move(const string &command)
{
	ChessNotation notation;
	
	if (!notation.parse(command)) return false;	//invalid command
	
	bool ret = this->chessBoard.move(notation);
	
	if (ret)
		// save command
		this->saveCommandToNotationFile(command);

	return ret;
}

void ChineseChess::saveCommandToNotationFile(const string &command)
{
	ofstream out;
	
	out.open(this->notationFile);
	
	out << command << endl;

	out.close();
}

