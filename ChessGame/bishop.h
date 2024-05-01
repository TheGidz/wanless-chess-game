#ifndef bishop_H
#define bishop_H
#include "game_piece.h"


class bishop : public game_piece
{
public:
	bishop(Player owner);
	~bishop();
	
private:
	bool move_is_legal(game_piece* board[8], int column, int row, bool verbose) override;

};

#endif // bishop_H
