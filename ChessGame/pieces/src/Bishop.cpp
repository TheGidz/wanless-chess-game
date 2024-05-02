#include "../inc/bishop.h"

Bishop::Bishop(Player owner) : GamePiece{owner, GamePieceType::GAME_PIECE_BISHOP}
{
}

Bishop::~Bishop()
{
}

bool Bishop::moveIsLegal(GamePiece *board[8], int newRow, int newColumn, bool verbose)
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

	// Next, check to make sure the move is diagonal
	if ((abs(currentColumn - newColumn)) != (abs(currentRow - newRow)))
	{
		if (verbose)
		{
			printf("Bishops must move diagonally.");
		}
		return false;
	}

	// Checks out, see if it's legal diagonal movement
	if (!legalDiagonal(board, newRow, newColumn, currentRow, currentColumn, verbose))
	{
		return false;
	}

	// Finally, does the move take the player's own piece
	if (takesOwnPiece(board, newLocation, verbose))
	{
		return false;
	}
	return true;
}
