#ifndef ROOK_H
#define ROOK_H
#include "game_piece.h"


class rook : public game_piece
{
public:
	rook(Player owner);
	~rook();
	
private:
	bool move_is_legal(game_piece* board[8], int column, int row, bool verbose) override;

};

#endif // ROOK_H
