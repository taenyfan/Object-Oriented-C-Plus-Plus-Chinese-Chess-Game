/**
 *
 */

#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "piece-horse.h"


PieceHorse::PieceHorse(ChessPlayer player) : Piece(CC_PIECE_HORSE, "H", "Horse", player)
{
	
}

PieceHorse::~PieceHorse()
{
	
}

bool PieceHorse::validateStep(PieceDirection direction, int steps)
{
	if (direction == CC_PIECE_DIR_HORIZ)
	{
		return false;  // horse can not move in horizontal
	}
	else if (direction == CC_PIECE_DIR_FORWARD)
	{
		this->ty = (this->player == CC_PLAYER_BLACK ? this->y - 2 : this->y + 2);
		this->tx = (this->player == CC_PLAYER_BLACK ? 9 - steps : steps - 1);

		if (abs(this->tx - this->x) != 1) return false;
	}
	else if (direction == CC_PIECE_DIR_BACKWARD)
	{
		this->ty = (this->player == CC_PLAYER_BLACK ? this->y + 2 : this->y - 2);
		this->tx = (this->player == CC_PLAYER_BLACK ? 9 - steps : steps - 1);

		if (abs(this->tx - this->x) != 1) return false;
	}

	if (!this->checkBoardBoundary()) return false;

	return true;
}
