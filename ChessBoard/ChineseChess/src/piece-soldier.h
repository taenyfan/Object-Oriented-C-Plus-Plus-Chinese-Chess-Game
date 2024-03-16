/*
 *
 */

#ifndef _PIECE_SOLDIER_H
#define _PIECE_SOLDIER_H

#include "piece.h"


//	Soldier piece definition

class PieceSoldier : public Piece
{
public:
	PieceSoldier(ChessPlayer player = CC_PLAYER_RED);
	~PieceSoldier();
	
	bool validateStep(PieceDirection direction, int steps);
	
public:
	
};


#endif
