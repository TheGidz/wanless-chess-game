#include "../inc/Queen.h"

Queen::Queen(Player owner)
	: GamePiece{owner, GamePieceType::GAME_PIECE_QUEEN}
{
}

Queen::~Queen()
{
}

bool Queen::moveIsLegal(GamePiece *board[8], int newRow, int newColumn, bool verbose)
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

	(verbose) ? std::cout << *this << " from column " << currentColumn + 1 << ", row " << currentRow + 1
						  << " to column " << newColumn + 1 << ", row " << newRow + 1 << std::endl
			  : std::cout << "";

	// First, make sure the move is actually a move.
	if (!doesMove(newRow, newColumn, currentRow, currentColumn, verbose))
	{
		return false;
	}

	// if the movement is horizontal/vertical, apply horizontal/vertical movement logic as with rooks
	if ((newColumn == currentColumn) || (newRow == currentRow))
	{
		// if the movement is horizontal/vertical, apply horizontal/vertical movement logic as with rooks
		if (!legalStraight(board, newRow, newColumn, currentRow, currentColumn, verbose))
		{
			return false;
		}
	}
	else
		// Next, check to make sure the move is diagonal
		if ((abs(currentColumn - newColumn)) == (abs(currentRow - newRow)))
		{
			// if the movement is diagonal, apply diagonal movement logic as with bishops
			if (!legalDiagonal(board, newRow, newColumn, currentRow, currentColumn, verbose))
			{
				return false;
			}
		}
		else
		{
			(verbose) ? std::cout << "Queens must move straight, or diagonally.\n" : std::cout << "";
			return false;
		}

	// Finally, let's make sure that we don't try to take our own piece
	if (takesOwnPiece(board, new_location, verbose))
	{
		return false;
	}
	return true;
}