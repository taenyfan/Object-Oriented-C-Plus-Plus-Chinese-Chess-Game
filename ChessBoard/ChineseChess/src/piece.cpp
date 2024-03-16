/**
*
*/

#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "piece.h"

//namespace CC
//{

Piece::Piece()
{
	this->reset();
	
	this->x = 0;
	this->y = 0;
	
	this->id = 0;
}
	
Piece::Piece(ChinesePiece type, const string &name, const string &desc, ChessPlayer player)
{
	this->type = type;
	this->name = name;
	this->description = desc;
	this->player = player;
	
	if (this->player == CC_PLAYER_RED)
		this->name = this->tolower(this->name);	// red piece name is in lowercase
}

Piece::~Piece()
{
	
}

bool Piece::validPieceName(const char name)
{
	string pieceName = "GRHEACS";
	
	char cc = this->toupper(name);
	
	if (cc == 'G' || cc == 'R' || cc == 'H' ||
		cc == 'E' || cc == 'A' || cc == 'C' ||
		cc == 'S')
		return true;
	
	return false;
}

void Piece::reset()
{
	this->state = CC_PIECE_STATE_ACTIVE;
}

bool Piece::validateStep(PieceDirection direction, int steps)
{
	return true;
}

bool Piece::checkBoardBoundary()
{
	if (this->tx < 0 || this->tx > 8 ||
		this->ty < 0 || this->ty > 9)
		return false;

	return true;
}

string Piece::tolower(string &str)
{
	for (int i = 0; i < str.length(); i++)
	{
		char cc = str[i];
		if (cc >= 'A' && cc <= 'Z')
			str[i] = cc - 'A' + 'a';
	}
	
	return str;
}

string Piece::toupper(string &str)
{
	for (int i = 0; i < str.length(); i++)
	{
		char cc = str[i];
		if (cc >= 'a' && cc <= 'z')
			str[i] = cc - 'a' + 'A';
	}
	
	return str;
}

char Piece::tolower(char cc)
{
	if (cc >= 'A' && cc <= 'Z')
		cc = cc - 'A' + 'a';
	
	return cc;
}

char Piece::toupper(char cc)
{
	if (cc >= 'a' && cc <= 'z')
		cc = cc - 'a' + 'A';
	
	return cc;
}

//}


