#ifndef ROOK_H
#define ROOK_H
#include "GamePiece.h"

class Rook : public GamePiece
{
public:
	Rook(Player owner);
	~Rook();

private:
	bool moveIsLegal(GamePiece *board[8], int column, int row, bool verbose) override;
};

#endif // ROOK_H
