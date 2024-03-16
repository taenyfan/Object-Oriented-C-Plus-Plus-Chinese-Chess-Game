/*
 *
 */

#ifndef _PIECE_CHARIOT_H
#define _PIECE_CHARIOT_H

#include "piece.h"


//	Chariot piece definition

class PieceChariot : public Piece
{
public:
	PieceChariot(ChessPlayer player = CC_PLAYER_RED);
	~PieceChariot();
	
	bool validateStep(PieceDirection direction, int steps);
	
public:
	
};


#endif
