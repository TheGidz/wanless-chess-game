#ifndef PAWN_H
#define PAWN_H
#include "game_piece.h"


class pawn : public game_piece
{
public:
	pawn(Player owner);
	~pawn();
	
private:
	bool move_is_legal(game_piece* board[8], int column, int row, bool verbose) override;

};

#endif // PAWN_H
