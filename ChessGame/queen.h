#ifndef queen_H
#define queen_H
#include "game_piece.h"


class queen : public game_piece
{
public:
	queen(Player owner);
	~queen();
	
private:
	bool move_is_legal(game_piece* board[8], int column, int row, bool verbose) override;

};

#endif // queen_H
