#ifndef king_H
#define king_H
#include "game_piece.h"


class king : public game_piece
{
public:
	king(Player owner);
	~king();
	
private:
	bool move_is_legal(game_piece* board[8], int column, int row, bool verbose) override;

};

#endif // king_H
