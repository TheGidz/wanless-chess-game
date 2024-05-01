#include "../inc/Pawn.h"

Pawn::Pawn(Player owner)
	: GamePiece{owner, GamePieceType::GAME_PIECE_PAWN}
{
}

Pawn::~Pawn()
{
}

bool Pawn::moveIsLegal(GamePiece *board[8], int newRow, int newColumn, bool verbose)
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

	(verbose) ? std::cout << *this << " from column " << currentColumn + 1 << ", row " << currentRow + 1
						  << " to column " << newColumn + 1 << ", row " << newRow + 1 << std::endl
			  : std::cout << "";

	// First, make sure the move is actually a move.
	if (!doesMove(newRow, newColumn, currentRow, currentColumn, verbose))
	{
		return false;
	}

	// Next let's make sure that we don't try to take our own piece
	if (takesOwnPiece(board, newLocation, verbose))
	{
		return false;
	}

	// movement logic for white pawns
	if (this->getOwner() == 'W')
	{
		// First move as a double move logic
		if ((newColumn == currentColumn) && (newRow == (currentRow + 2)))
		{
			if (this->getHasMoved() == false)
			{
				if (board[newLocation] == nullptr)
				{
					// Double move exposes pawn to en passant
					this->setEnPassant(true);
					return true;
				}
			}
			else
			{
				(verbose) ? std::cout << "Pawns can only double move on their first move.\n" : std::cout << "";
			}
		}
		if ((newColumn == currentColumn) && (newRow == (currentRow + 1)))
		{
			if (board[newLocation] == nullptr)
			{
				return true;
			}
			(verbose) ? std::cout << "This space is not empty, and pawns cannot take pieces this way.\n" : std::cout << "";
		}
		// Logic to detect legal taking pieces
		if (((newColumn == currentColumn + 1) || (newColumn == currentColumn - 1)) && (newRow == currentRow + 1) && (board[newLocation] != nullptr) && (board[newLocation]->getOwner() != this->getOwner()))
		{
			return true;
		}
		// Logic to detect legal en passant
		if (((newColumn == currentColumn + 1) || (newColumn == currentColumn - 1)) && (newRow == currentRow + 1) && (board[newLocation] == nullptr) && (board[newLocation - 8] != nullptr) && (board[newLocation - 8]->getOwner() != this->getOwner()) && (board[newLocation - 8]->getPieceType() == GamePieceType::GAME_PIECE_PAWN) && (board[newLocation - 8]->getEnPassant() == true))
		{
			// Deleting a piece from here causes problems, so instead we will move the piece that is being taken
			// to where other logic can delete it for us cleanly.
			board[newLocation] = board[newLocation - 8];
			board[newLocation - 8] = 0;
			return true;
		}
	}

	// movement logic for black pawns
	if (this->getOwner() == 'B')
	{
		// First move is a double move
		if ((newColumn == currentColumn) && (newRow == (currentRow - 2)))
		{
			if (this->getHasMoved() == false)
			{
				if (board[newLocation] == nullptr)
				{
					// Double move exposes pawn to en passant
					this->setEnPassant(true);
					return true;
				}
			}
			else
			{
				(verbose) ? std::cout << "Pawns can only double move on their first move.\n" : std::cout << "";
			}
		}
		if ((newColumn == currentColumn) && (newRow == (currentRow - 1)))
		{
			if (board[newLocation] == nullptr)
			{
				return true;
			}
			(verbose) ? std::cout << "This space is not empty, and this piece cannot take pieces this way.\n" : std::cout << "";
		}
		// Logic to detect legal taking pieces
		if (((newColumn == currentColumn + 1) || (newColumn == currentColumn - 1)) && (newRow == currentRow - 1) && (board[newLocation] != nullptr) && (board[newLocation]->getOwner() != this->getOwner()))
		{
			return true;
		}
		// Logic to detect legal en passant
		if (((newColumn == currentColumn + 1) || (newColumn == currentColumn - 1)) && (newRow == currentRow - 1) && (board[newLocation] == nullptr) && (board[newLocation + 8] != nullptr) && (board[newLocation + 8]->getOwner() != this->getOwner()) && (board[newLocation + 8]->getPieceType() == 'P') && (board[newLocation + 8]->getEnPassant() == true))
		{
			// Deleting a piece from here causes problems, so instead we will move the piece that is being taken
			// to where other logic can delete it for us cleanly.
			board[newLocation] = board[newLocation + 8];
			board[newLocation + 8] = 0;
			return true;
		}
	}
	return false;
}
