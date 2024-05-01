#ifndef knight_H
#define knight_H
#include "game_piece.h"


class knight : public game_piece
{
public:
	knight(Player owner);
	~knight();
	
private:
	bool move_is_legal(game_piece* board[8], int column, int row, bool verbose) override;

};

#endif // knight_H
