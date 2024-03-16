/*
 *
 */

#ifndef _PIECE_H
#define _PIECE_H


using namespace std;

//  Pieces define
//
	
typedef enum _players
{
	CC_PLAYER_RED = 0,
	CC_PLAYER_BLACK = 1
}
ChessPlayer;

typedef enum _pieces
{
	CC_PIECE_NIL,
	CC_PIECE_GENERAL,
	CC_PIECE_ADVISOR,
	CC_PIECE_ELEPHANT,
	CC_PIECE_HORSE,
	CC_PIECE_CHARIOT,
	CC_PIECE_CANNON,
	CC_PIECE_SOLDIER
	
} ChinesePiece;

// define the state of piece.
typedef enum _piese_state
{
	CC_PIECE_STATE_INACTIVE = 0,	///< inactive piece, has been captured
	CC_PIECE_STATE_ACTIVE	= 1		///< active piece on chess board
	
} PieceState;

// define the direction of a piece to move
typedef enum _piece_direction
{
	CC_PIECE_DIR_FORWARD = 0,	// move forward
	CC_PIECE_DIR_BACKWARD = 1,  // move backword
	CC_PIECE_DIR_HORIZ = 2		// move left/right

} PieceDirection;

class ChineseChessBoard;

//	Basic piece definition

class Piece
{
public:
	Piece();
	Piece(ChinesePiece type, const string &name, const string &desc, ChessPlayer player);
	~Piece();
	
	char getName() { return this->name[0]; };
	
	bool validPieceName(const char name); ///< check if it is a valid piece name
	
	void reset();			///< reset piece state to active
	
	virtual bool validateStep(PieceDirection direction, int steps);	///< validate the move by rules for the piece
	
protected:

	bool checkBoardBoundary();    ///< check if it move outside chess board

	string tolower(string &str);  ///< convert a string to lowercase string
	string toupper(string &str);  ///< convert a string to uppercase string
	char toupper(char cc); 		  ///< convert char to uppercase
	char tolower(char cc); 		  ///< convert char to uppercase

public:
	
	int 	id;				///< index of piece
	ChinesePiece type;		///< the piece type
	string 	name;			///< short name of piece
	string  description;	///< long name of piece
	
	int x, y;				///< location of piece on chess board
	int tx, ty;				///< target location of piece to move to

	PieceState state;		///< state of the piece. When the piece is captured
	///< by enemy, set piece state to inactive.
	ChessPlayer player;		///< red/black player

	ChineseChessBoard *chessBoard;
};


#endif
