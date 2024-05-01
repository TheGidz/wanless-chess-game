#ifndef GAME_PIECE_H_
#define GAME_PIECE_H_
#include <string>
#include <iostream>
#include "..\..\inc\Enums.hpp"

class GamePiece
{
private:
	GamePiece();
	const Player m_owner;
	const GamePieceType m_pieceType;
	bool m_hasMoved;
	bool m_enPassant;

public:
	GamePiece(Player owner, GamePieceType pieceType);
	virtual ~GamePiece();
	virtual bool moveIsLegal(GamePiece *board[8], int column, int row, bool verbose);

	bool legalDiagonal(GamePiece *board[8], int newRow, int newColumn, int currentRow, int currentColumn, bool verbose);
	bool legalStraight(GamePiece *board[8], int newRow, int newColumn, int currentRow, int currentColumn, bool verbose);
	bool getEnPassant();
	bool getHasMoved();
	GamePieceType getPieceType();
	Player getOwner();
	void setEnPassant(bool setting);
	void setHasMoved(bool setting);
	void printPiece(std::ostream &os) const;
	bool inBounds(int row, int column, bool verbose);
	bool doesMove(int new_column, int newRow, int currentColumn, int currentRow, bool verbose);
	bool takesOwnPiece(GamePiece *board[8], int newLocation, bool verbose);
	void findOnBoard(GamePiece *board[8], int &currentLocation, int &currentRow, int &currentColumn);

	friend std::ostream &operator<<(std::ostream &os, const GamePiece &piece);
};

#endif // GAME_PIECE_H_
