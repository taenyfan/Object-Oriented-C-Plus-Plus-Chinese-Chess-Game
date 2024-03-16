/*
 *
 */

#ifndef _PIECE_GENERAL_H
#define _PIECE_GENERAL_H

#include "piece.h"


//	General piece definition

class PieceGeneral : public Piece
{
public:
	PieceGeneral(ChessPlayer player = CC_PLAYER_RED);
	~PieceGeneral();
	
	bool validateStep(PieceDirection direction, int steps);
	
public:
	
};


#endif
