/*
 *
 */

#ifndef _PIECE_ELEPHANT_H
#define _PIECE_ELEPHANT_H

#include "piece.h"


//	Elephant piece definition

class PieceElephant : public Piece
{
public:
	PieceElephant(ChessPlayer player = CC_PLAYER_RED);
	~PieceElephant();
	
	bool validateStep(PieceDirection direction, int steps);
	
public:
	
};


#endif
