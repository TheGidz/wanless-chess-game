#include "../inc/Rook.h"

Rook::Rook(Player owner)
	: GamePiece{owner, GamePieceType::GAME_PIECE_ROOK}
{
}

Rook::~Rook()
{
}

bool Rook::moveIsLegal(GamePiece *board[8], int newRow, int newColumn, bool verbose)
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

	// First, make sure the move is actually a move.
	if (!doesMove(newRow, newColumn, currentRow, currentColumn, verbose))
	{
		return false;
	}

	// check to make sure it's straight movement
	if ((newColumn == currentColumn) || (newRow == currentRow))
	{
		// if the movement is horizontal/vertical, apply horizontal/vertical movement logic as with rooks
		if (!legalStraight(board, newRow, newColumn, currentRow, currentColumn, verbose))
		{
			return false;
		}
	}
	else
	{
		if (verbose)
		{
			printf("Rooks must move straight.");
		}
		return false;
	}

	// Next let's make sure that we don't try to take our own piece
	if (takesOwnPiece(board, newLocation, verbose))
	{
		return false;
	}
	return true;
}
