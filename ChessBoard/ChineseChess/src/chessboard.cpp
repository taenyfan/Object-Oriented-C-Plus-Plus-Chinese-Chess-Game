/**
*
*/

#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "chessboard.h"
#include "piece-general.h"
#include "piece-advisor.h"
#include "piece-chariot.h"
#include "piece-cannon.h"
#include "piece-elephant.h"
#include "piece-horse.h"
#include "piece-soldier.h"


/******************************************************************************
// Chinese chess board
 
 			Player (Red)
 
1        2        3        4        5        6        7        8        9
rrr------hhh------eee------aaa------ggg------aaa------eee------hhh------rrr
|        |        |        |        |        |        |        |        |
|        |        |        |        |        |        |        |        |
---------------------------------------------------------------------------
|        |        |        |        |        |        |        |        |
|        |        |        |        |        |        |        |        |
---------ccc---------------------------------------------------ccc---------
|        |        |        |        |        |        |        |        |
|        |        |        |        |        |        |        |        |
sss---------------sss---------------sss---------------sss---------------sss
|        |        |        |        |        |        |        |        |
|        |        |        |        |        |        |        |        |
---------------------------------------------------------------------------
|                                    < < < < < < < < < < < < < < < <    |
|    > > > > > > > > > > > > > > > >                                    |
---------------------------------------------------------------------------
|        |        |        |        |        |        |        |        |
|        |        |        |        |        |        |        |        |
SSS---------------SSS---------------SSS---------------SSS---------------SSS
|        |        |        |        |        |        |        |        |
|        |        |        |        |        |        |        |        |
---------CCC---------------------------------------------------CCC---------
|        |        |        |        |        |        |        |        |
|        |        |        |        |        |        |        |        |
---------------------------------------------------------------------------
|        |        |        |        |        |        |        |        |
|        |        |        |        |        |        |        |        |
RRR------HHH------EEE------AAA------GGG------AAA------EEE------HHH------RRR

9        8        7        6        5        4        3        2        1

 			Player (Black)

 *****************************************************************************/


ChineseChessBoard::ChineseChessBoard()
{
	// initial chess board matrix. Red piece is in lowercase. Black piese is in UPPERCASE.
	char matrix[10][9] = {
		{ 'r',  'h',  'e',  'a',  'g',  'a',  'e',  'h',  'r' },
		
		{ ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ' },
		
		{ ' ',  'c',  ' ',  ' ',  ' ',  ' ',  ' ',  'c',  ' ' },
		
		{ 's',  ' ',  's',  ' ',  's',  ' ',  's',  ' ',  's' },
		
		{ ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ' },
		
		{ ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ' },
		
		{ 'S',  ' ',  'S',  ' ',  'S',  ' ',  'S',  ' ',  'S' },
		
		{ ' ',  'C',  ' ',  ' ',  ' ',  ' ',  ' ',  'C',  ' ' },
		
		{ ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ' },
		
		{ 'R',  'H',  'E',  'A',  'G',  'A',  'E',  'H',  'R' },
	};
	
	this->backupMatrix(matrix);
	
	// create the chess board from this matrix
	this->createChessBoard(matrix);
	
	this->gameOver = false;
}

ChineseChessBoard::~ChineseChessBoard()
{
	this->clearChessBoard();
}

void ChineseChessBoard::clearChessBoard()
{
	// release piece memory
	if (this->m_pieceList.size() > 0)
	{
		for (int i = 0; i < this->m_pieceList.size(); i++)
		{
			delete this->m_pieceList[i];
		}

		this->m_pieceList.clear();
	}
	
	// clear captured pieces for players
	this->m_capturedPieceList[CC_PLAYER_RED].clear();
	this->m_capturedPieceList[CC_PLAYER_BLACK].clear();
	
	// clear the chess board matrix
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
			this->board[i][j] = NULL;
	}
}

void ChineseChessBoard::backupMatrix(char matrix[][9])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
			this->defaultMatrix[i][j] = matrix[i][j];
	}
}

void ChineseChessBoard::createChessBoard(char matrix[][9])
{
	this->clearChessBoard();
	
	//create pieces for red and black players
	int count = 0;
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			char cc = matrix[i][j];
			
			if (cc == ' ') continue;	// no piece at this location
			
			Piece *piece = NULL;
			
			ChessPlayer player;
			
			if (cc >= 'a' && cc <= 'z')
			{
				player = CC_PLAYER_RED;
				cc = cc - 'a' + 'A';
			}
			else
				player = CC_PLAYER_BLACK;
			
			if (cc == 'R')
			{
				piece = new PieceChariot(player);
				if (piece == NULL) continue;
				
				piece->x = j;
				piece->y = i;
			}
			else if (cc == 'H')
			{
				piece = new PieceHorse(player);
				if (piece == NULL) continue;
				
				piece->x = j;
				piece->y = i;
			}
			else if (cc == 'E')
			{
				piece = new PieceElephant(player);
				if (piece == NULL) continue;
				
				piece->x = j;
				piece->y = i;
			}
			else if (cc == 'A')
			{
				piece = new PieceAdvisor(player);
				if (piece == NULL) continue;
				
				piece->x = j;
				piece->y = i;
			}
			else if (cc == 'G')
			{
				piece = new PieceGeneral(player);
				if (piece == NULL) continue;
				
				piece->x = j;
				piece->y = i;
			}
			else if (cc == 'C')
			{
				piece = new PieceCannon(player);
				if (piece == NULL) continue;
				
				piece->x = j;
				piece->y = i;
			}
			else if (cc == 'S')
			{
				piece = new PieceSoldier(player);
				if (piece == NULL) continue;
				
				piece->x = j;
				piece->y = i;
			}
			
			if (piece)
			{
				piece->id = count++;
				this->m_pieceList.push_back(piece);
			}
		}
	}
	
	// With the pieces in piese list, build a piece matrix
	for (int i = 0; i < this->m_pieceList.size(); i++)
	{
		Piece *p = this->m_pieceList[i];
		
		this->board[p->y][p->x] = p;
	}
}

void ChineseChessBoard::reset()
{
	this->clearChessBoard();
	
	this->createChessBoard(this->defaultMatrix);
	
	this->gameOver = false;
}

void ChineseChessBoard::printChessBoard()
{
	char matrix[10][9] = {' '};
	
	for (int i = 0; i < this->m_pieceList.size(); i++)
	{
		Piece *p = this->m_pieceList[i];
		
		matrix[p->y][p->x] = p->name[0];
	}
	
	cout << endl;
	cout << "     1        2        3        4        5        6        7        8        9  "  << endl;

	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			cout << "     |                                    < < < < < < < < < < < < < < < <    |  "  << endl;
			cout << "     |    > > > > > > > > > > > > > > > >                                    |  "  << endl;
		}
		else if (i > 0)
		{
			cout << "     |        |        |        |        |        |        |        |        |  "  << endl;
			cout << "     |        |        |        |        |        |        |        |        |  "  << endl;
		}
		
		cout << "    ";
		
		for (int j = 0; j < 9; j++)
		{
			Piece *p = this->board[i][j];
			char cc = (p != NULL ? p->getName() : ' ');
			
			if (j > 0) cout << "------";
			
			if (cc != ' ')
				cout << cc << cc << cc;
			else
				cout << "---";
		}
		
		cout << endl;
	}


	cout << endl;
	cout << "     9        8        7        6        5        4        3        2        1  "  << endl;
	cout << endl;
	
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
			cout << "   Red captured:   ";
		else
			cout << "   Black captured: ";
	
		for (int j = 0; j < this->m_capturedPieceList[i].size(); j++)
		{
			char cc = this->m_capturedPieceList[i][j]->getName();
			if (j > 0) cout << "   ";
			cout << cc;
		}
		
		cout << endl;
	}
}

bool ChineseChessBoard::move(const ChessNotation &notation)
{
	Piece piece;
	ChessNotation *pNotation = (ChessNotation *)&notation;
	
	// Accept valid piece name only
	if (!piece.validPieceName(notation.pieceName))
	{
		cout << "invalid piece name: " << notation.pieceName << endl;
		return false;
	}
	
	pNotation->dump();
	
	// Pickup the piece at the column in chess board
	Piece *srcPiece = NULL;
	
	for (int i = 0; i < 10; i++)
	{
		Piece *p = NULL;
		
		if (notation.player == CC_PLAYER_RED)
			p = this->board[i][notation.col - 1];
		else
			p = this->board[9 - i][9 - notation.col];
		
		//if (p)
		//	cout << "p: " << i << "  " << p->getName() << "  " << notation.pieceName << endl;
		
		if (p != NULL && p->getName() == notation.pieceName)
		{
			srcPiece = p;
			break;
		}
	}
	
	if (srcPiece == NULL)
	{
		cout << "can not find piece: " << notation.pieceName << "  at col " << notation.col << endl;
		return false;
	}
	
	// check if the movement is valid for piece
	if (!srcPiece->validateStep(notation.direction, notation.step))
	{
		// the movement is not applicable to this piece
		cout << "validation fail by piece rule" << endl;
		return false;
	}

	// Get the piece in target location on chess board
	
	Piece *dstPiece = this->board[srcPiece->ty][srcPiece->tx];
	
	// check for same player
	if (dstPiece != NULL)
	{
		if (dstPiece->player == srcPiece->player)
		{
			// Not able to move to this location
			cout << "not available location" << endl;
			return false;
		}
		else
		{
			// capture the enemy piece
			this->m_capturedPieceList[srcPiece->player].push_back(dstPiece);

			// move src piece to dst location
			this->board[srcPiece->y][srcPiece->x] = NULL;
			this->board[dstPiece->y][dstPiece->x] = srcPiece;
			srcPiece->x = dstPiece->x;
			srcPiece->y = dstPiece->y;
			
			if (dstPiece->getName() == 'g' ||
				dstPiece->getName() == 'G')
				this->gameOver = true;
		}
	}
	else
	{
		cout << "move to: " << srcPiece->x << "  " << srcPiece->y << "  to " << srcPiece->tx << "  " << srcPiece->ty << endl;
		// move src piece to new location
		this->board[srcPiece->y][srcPiece->x] = NULL;
		cout << "__" << endl;
		this->board[srcPiece->ty][srcPiece->tx] = srcPiece;
		cout << "__" << endl;
		srcPiece->x = srcPiece->tx;
		srcPiece->y = srcPiece->ty;
		
		cout << "__" << endl;
	}
	//
	
	return true;
}

/////////////////////////////////////////////////////////////////////
bool ChessNotation::parse(const string &command)
{
	string cmd = command;
	
	// remove spaces in the string
	int len = 0;
	for (int i = 0; i < command.length(); i++)
	{
		if (command[i] != ' ') cmd[len++] = command[i];
	}
	
	cmd = cmd.substr(0, len);
	
	// at least 4 chars in the command
	if (cmd.length() < 4) return false;
	
	// first char is the piece name
	this->pieceName = cmd[0];
	
	if (this->pieceName >= 'a' && this->pieceName <= 'z')
		this->player = CC_PLAYER_RED;
	else
		this->player = CC_PLAYER_BLACK;
	
	// second char if the col number of the piece
	string str;
	str = cmd[1];
	this->col = atoi(str.c_str());
	
	if (this->col < 1 || this->col > 9) return false;
	
	// third char is the direction of the piece to move
	char cc = cmd[2];
	if (cc == '.' || cc == '=')
		this->direction = CC_PIECE_DIR_HORIZ;
	else if (cc == '+')
		this->direction = CC_PIECE_DIR_FORWARD;
	else if (cc == '-')
		this->direction = CC_PIECE_DIR_BACKWARD;
	else
		return false;
	
	// fourth char is the moving steps or col number
	str = cmd[3];
	
	this->step = atoi(str.c_str());
	if (this->step < 1 || this->step > 9) return false;
	
	return true;
}

void ChessNotation::dump()
{
	cout << this->pieceName << this->col;
	if (this->direction == CC_PIECE_DIR_HORIZ)
		cout << "=";
	else if (this->direction == CC_PIECE_DIR_FORWARD)
		cout << "+";
	else if (this->direction == CC_PIECE_DIR_BACKWARD)
		cout << "-";
	cout << this->step;
	cout << endl;
}

