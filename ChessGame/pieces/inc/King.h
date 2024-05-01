#ifndef king_H
#define king_H
#include "GamePiece.h"

class King : public GamePiece
{
public:
	King(Player owner);
	~King();

private:
	bool moveIsLegal(GamePiece *board[8], int column, int row, bool verbose) override;
};

#endif // king_H
