/*
 *
 */

#ifndef _PIECE_CANNON_H
#define _PIECE_CANNON_H

#include "piece.h"


//	Cannon piece definition

class PieceCannon : public Piece
{
public:
	PieceCannon(ChessPlayer player = CC_PLAYER_RED);
	~PieceCannon();
	
	bool validateStep(PieceDirection direction, int steps);
	
public:
	
};


#endif
