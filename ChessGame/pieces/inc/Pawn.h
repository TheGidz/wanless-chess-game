#ifndef PAWN_H
#define PAWN_H
#include "GamePiece.h"

class Pawn : public GamePiece
{
public:
	Pawn(Player owner);
	~Pawn();

private:
	bool moveIsLegal(GamePiece *board[8], int column, int row, bool verbose) override;
};

#endif // PAWN_H
