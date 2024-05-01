#ifndef bishop_H
#define bishop_H
#include "GamePiece.h"

class Bishop : public GamePiece
{
public:
	Bishop(Player owner);
	~Bishop();

private:
	bool moveIsLegal(GamePiece *board[8], int column, int row, bool verbose) override;
};

#endif // bishop_H
