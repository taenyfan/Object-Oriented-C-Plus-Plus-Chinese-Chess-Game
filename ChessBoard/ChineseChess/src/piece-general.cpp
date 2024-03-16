/**
*
*/

#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "piece-general.h"


PieceGeneral::PieceGeneral(ChessPlayer player) : Piece(CC_PIECE_GENERAL, "G", "Genreal", player)
{
	
}

PieceGeneral::~PieceGeneral()
{
	
}

bool PieceGeneral::validateStep(PieceDirection direction, int steps)
{
	if (direction == CC_PIECE_DIR_HORIZ)
	{
		if (steps < 4 || steps > 6)
			return false;
		
		this->tx = (this->player == CC_PLAYER_BLACK ? 9 - steps : steps - 1);
		this->ty = this->y;
		
		if (this->x == this->tx) return false; // same location
	}
	else if (direction == CC_PIECE_DIR_FORWARD)
	{
		if (steps != 1) return false;  // General can move 1 step only
		
		this->tx = this->x;
		this->ty = (this->player == CC_PLAYER_BLACK ? this->y - steps : this->y + steps);
		
		// General can move in Tian char only
		if (this->ty < 0 || this->ty > 9 || (this->ty > 2 && this->ty < 7)) return false;
	}
	else if (direction == CC_PIECE_DIR_BACKWARD)
	{
		if (steps != 1) return false;  // General can move 1 step only
		
		this->tx = this->x;
		this->ty = (this->player == CC_PLAYER_BLACK ? this->y + steps : this->y - steps);
		
		// General can move in Tian char only
		if (this->ty < 0 || this->ty > 9 || (this->ty > 2 && this->ty < 7)) return false;
	}

	if (!this->checkBoardBoundary()) return false;

	return true;
}
