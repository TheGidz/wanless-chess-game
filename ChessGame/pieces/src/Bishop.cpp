#include "../inc/bishop.h"

Bishop::Bishop(Player owner) : GamePiece{owner, GamePieceType::GAME_PIECE_BISHOP}
{
}

Bishop::~Bishop()
{
}

bool Bishop::moveIsLegal(GamePiece *board[8], int new_row, int new_column, bool verbose)
{
	// check the bounds of the board first
	if (!inBounds(new_row, new_column, verbose))
	{
		return false;
	}

	// find the current piece on the board
	int current_location = -1;
	int current_row{-1};
	int current_column{-1};
	findOnBoard(board, current_location, current_row, current_column);

	int new_location = (new_row * 8) + new_column;

	(verbose) ? std::cout << *this << " from column " << current_column + 1 << ", row " << current_row + 1
						  << " to column " << new_column + 1 << ", row " << new_row + 1 << std::endl
			  : std::cout << "";

	// First, make sure the move is actually a move.
	if (!doesMove(new_row, new_column, current_row, current_column, verbose))
	{
		return false;
	}

	// Next, check to make sure the move is diagonal
	if ((abs(current_column - new_column)) != (abs(current_row - new_row)))
	{
		(verbose) ? std::cout << "Bishops must move diagonally.\n" : std::cout << "";
		return false;
	}

	// Checks out, see if it's legal diagonal movement
	if (!legalDiagonal(board, new_row, new_column, current_row, current_column, verbose))
	{
		return false;
	}

	// Finally, does the move take the player's own piece
	if (takesOwnPiece(board, new_location, verbose))
	{
		return false;
	}
	return true;
}
