#include "../inc/Knight.h"

Knight::Knight(Player owner)
	: GamePiece{owner, GamePieceType::GAME_PIECE_KNIGHT}
{
}

Knight::~Knight()
{
}

bool Knight::moveIsLegal(GamePiece *board[8], int newRow, int newColumn, bool verbose)
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

	int new_location = (newRow * 8) + newColumn;

	if (verbose)
	{
		printf("%s from column %d, row %d to column %d, row %d.", this->getPieceTypeString().c_str(), currentColumn + 1, currentRow + 1, newColumn + 1, newRow + 1);
	}

	// First, make sure the move is actually a move.
	if (!doesMove(newRow, newColumn, currentRow, currentColumn, verbose))
	{
		return false;
	}

	// movement logic.  Lots of conditions to check in order to make any of the 8 L shaped movements accepted by Knight movement.
	if ((((newColumn == currentColumn + 1) || (newColumn == currentColumn - 1)) && ((newRow == (currentRow - 2)) || (newRow == currentRow + 2))) || (((newColumn == currentColumn + 2) || (newColumn == currentColumn - 2)) && ((newRow == (currentRow - 1)) || (newRow == currentRow + 1))))
	{
		// So long as this move doesn't take the player's own piece, it's legal
		if (!takesOwnPiece(board, new_location, verbose))
		{
			return true;
		}
	}
	return false;
}
