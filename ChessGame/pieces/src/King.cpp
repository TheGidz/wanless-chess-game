#include "../inc/King.h"

King::King(Player owner)
	: GamePiece{owner, GamePieceType::GAME_PIECE_KING}
{
}

King::~King()
{
}

bool King::moveIsLegal(GamePiece *board[8], int newRow, int newColumn, bool verbose)
{
	// check the bounds of the board first
	if (!inBounds(newRow, newColumn, verbose))
	{
		return false;
	}

	// find the current piece on the board
	int currentLocation = -1;
	int currentRow{-1};
	int currentColumn{-1};
	findOnBoard(board, currentLocation, currentRow, currentColumn);

	int newLocation = (newRow * 8) + newColumn;

	if (verbose)
	{
		printf("%s from column %d, row %d to column %d, row %d.", this->getPieceTypeString().c_str(), currentColumn + 1, currentRow + 1, newColumn + 1, newRow + 1);
	}

	// movement logic
	if (((newColumn == currentColumn) || (newColumn == currentColumn + 1) || (newColumn == currentColumn - 1)) && ((newRow == currentRow) || (newRow == currentRow + 1) || (newRow == currentRow - 1)))
	{
		// As long as it doesn't take the player's own piece, it's legal.
		// Rules for castling cannot be calculated here, and thus are found in game.cpp
		if (!takesOwnPiece(board, newLocation, verbose))
		{
			return true;
		}
	}
	return false;
}