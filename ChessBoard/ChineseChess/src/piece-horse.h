/*
 *
 */

#ifndef _PIECE_HORSE_H
#define _PIECE_HORSE_H

#include "piece.h"


//	Horse piece definition

class PieceHorse : public Piece
{
public:
	PieceHorse(ChessPlayer player = CC_PLAYER_RED);
	~PieceHorse();
	
	bool validateStep(PieceDirection direction, int steps);
	
public:
	
};


#endif
