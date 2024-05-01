#ifndef queen_H
#define queen_H
#include "GamePiece.h"

class Queen : public GamePiece
{
public:
	Queen(Player owner);
	~Queen();

private:
	bool moveIsLegal(GamePiece *board[8], int column, int row, bool verbose) override;
};

#endif // queen_H
