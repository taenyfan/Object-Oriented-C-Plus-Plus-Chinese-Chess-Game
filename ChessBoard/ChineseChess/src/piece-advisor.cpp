/**
 *
 */

#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "piece-advisor.h"


PieceAdvisor::PieceAdvisor(ChessPlayer player) : Piece(CC_PIECE_ADVISOR, "A", "Advisor", player)
{
	
}

PieceAdvisor::~PieceAdvisor()
{
	
}

bool PieceAdvisor::validateStep(PieceDirection direction, int steps)
{
	if (direction == CC_PIECE_DIR_HORIZ)
	{
		return false;  // advisor can not move in horizontal
	}
	else if (direction == CC_PIECE_DIR_FORWARD)
	{
		this->ty = (this->player == CC_PLAYER_BLACK ? this->y - 1 : this->y + 1);
		this->tx = (this->player == CC_PLAYER_BLACK ? 9 - steps : steps - 1);
		
		if (this->tx < 3 || this->tx > 5) return false;
		if (this->ty < 0 || this->ty > 9 || (this->ty > 2 && this->ty < 7)) return false;
	}
	else if (direction == CC_PIECE_DIR_BACKWARD)
	{
		this->ty = (this->player == CC_PLAYER_BLACK ? this->y + 1 : this->y - 1);
		this->tx = (this->player == CC_PLAYER_BLACK ? 9 - steps : steps - 1);
		
		if (this->tx < 3 || this->tx > 5) return false;
		if (this->ty < 0 || this->ty > 9 || (this->ty > 2 && this->ty < 7)) return false;
	}
	
	if (!this->checkBoardBoundary()) return false;

	return true;
}
