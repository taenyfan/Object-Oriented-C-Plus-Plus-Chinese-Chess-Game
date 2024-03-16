/**
 *
 */

#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "piece-soldier.h"


PieceSoldier::PieceSoldier(ChessPlayer player) : Piece(CC_PIECE_SOLDIER, "S", "Soldier", player)
{
	
}

PieceSoldier::~PieceSoldier()
{
	
}

bool PieceSoldier::validateStep(PieceDirection direction, int steps)
{
	if (direction == CC_PIECE_DIR_HORIZ)
	{
		int row = (this->player == CC_PLAYER_BLACK ? 9 - this->y : this->y);
		if (row < 5) return false;	// Soldier can forward only before crossing the river
		
		this->tx = (this->player == CC_PLAYER_BLACK ? 9 - steps : steps - 1);
		this->ty = this->y;
		
		if (abs(this->tx - this->x) > 1) return false;
		
		if (this->x == this->tx) return false; // same location
	}
	else if (direction == CC_PIECE_DIR_FORWARD)
	{
		if (steps != 1) return false;  // Soldier can move 1 step only
		
		int dst = (this->player == CC_PLAYER_BLACK ? this->y - steps : this->y + steps);
		
		if (dst > 10) return false;
		
		this->tx = this->x;
		this->ty = dst;
	}
	else if (direction == CC_PIECE_DIR_BACKWARD)
	{
		return false;		// soldier can move forward only
	}
	
	if (!this->checkBoardBoundary()) return false;

	return true;
}
