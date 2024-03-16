/*
 *
 */

#ifndef _PIECE_ADVISOR_H
#define _PIECE_ADVISOR_H

#include "piece.h"


//	Advisor piece definition

class PieceAdvisor : public Piece
{
public:
	PieceAdvisor(ChessPlayer player = CC_PLAYER_RED);
	~PieceAdvisor();
	
	bool validateStep(PieceDirection direction, int steps);
	
public:
	
};


#endif
