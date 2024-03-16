/**
 *
 */

#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "piece-cannon.h"


PieceCannon::PieceCannon(ChessPlayer player) : Piece(CC_PIECE_CANNON, "C", "Cannon", player)
{
	
}

PieceCannon::~PieceCannon()
{
	
}

bool PieceCannon::validateStep(PieceDirection direction, int steps)
{
	if (direction == CC_PIECE_DIR_HORIZ)
	{
		this->tx = (this->player == CC_PLAYER_BLACK ? 9 - steps : steps - 1);
		this->ty = this->y;

		if (this->x == this->tx) return false; // same location
	}
	else if (direction == CC_PIECE_DIR_FORWARD)
	{
		this->tx = this->x;
		this->ty = (this->player == CC_PLAYER_BLACK ? this->y - steps : this->y + steps);
	}
	else if (direction == CC_PIECE_DIR_BACKWARD)
	{
		this->tx = this->x;
		this->ty = (this->player == CC_PLAYER_BLACK ? this->y + steps : this->y - steps);
	}

	if (!this->checkBoardBoundary()) return false;

	return true;
}
