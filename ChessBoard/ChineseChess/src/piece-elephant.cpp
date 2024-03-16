/**
 *
 */

#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "piece-elephant.h"


PieceElephant::PieceElephant(ChessPlayer player) : Piece(CC_PIECE_ELEPHANT, "E", "Elephant", player)
{
	
}

PieceElephant::~PieceElephant()
{
	
}

bool PieceElephant::validateStep(PieceDirection direction, int steps)
{
	if (direction == CC_PIECE_DIR_HORIZ)
	{
		return false;  // elephant can not move in horizontal
	}
	else if (direction == CC_PIECE_DIR_FORWARD)
	{
		this->ty = (this->player == CC_PLAYER_BLACK ? this->y - 2 : this->y + 2);
		this->tx = (this->player == CC_PLAYER_BLACK ? 9 - steps : steps - 1);

		int dy = (this->player == CC_PLAYER_BLACK ? 9 - this->ty : this->ty);
		if (dy > 4) return false;	// elephand can not cross river

		if (abs(this->tx - this->x) != 2) return false;
	}
	else if (direction == CC_PIECE_DIR_BACKWARD)
	{
		this->ty = (this->player == CC_PLAYER_BLACK ? this->y + 2 : this->y - 2);
		this->tx = (this->player == CC_PLAYER_BLACK ? 9 - steps : steps - 1);

		int dy = (this->player == CC_PLAYER_BLACK ? 9 - this->ty : this->ty);
		if (dy > 4) return false;	// elephand can not cross river

		if (abs(this->tx - this->x) != 2) return false;
	}

	if (!this->checkBoardBoundary()) return false;

	return true;
}
