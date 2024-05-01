#ifndef knight_H
#define knight_H
#include "GamePiece.h"

class Knight : public GamePiece
{
public:
	Knight(Player owner);
	~Knight();

private:
	bool moveIsLegal(GamePiece *board[8], int column, int row, bool verbose) override;
};

#endif // knight_H
