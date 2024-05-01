#include "bishop.h"

bishop::bishop(Player owner) :
game_piece {owner, GamePieceType::GAME_PIECE_BISHOP}
{
}

bishop::~bishop()
{
}

bool bishop::move_is_legal(game_piece* board[8], int new_row, int new_column, bool verbose) {
	//check the bounds of the board first
	if (!in_bounds (new_row, new_column, verbose)) {
		return false;
	}
	
	//find the current piece on the board
	int current_location = -1;
	int current_row {-1};
	int current_column {-1};
	find_on_board(board, current_location, current_row, current_column);

	int new_location = (new_row*8) + new_column;
	
	(verbose) ? std::cout << *this << " from column " << current_column+1 << ", row " << current_row+1
						  << " to column " << new_column+1 << ", row " << new_row+1 << std::endl : std::cout << "";
	
	//First, make sure the move is actually a move.
	if (!does_move(new_row, new_column, current_row, current_column, verbose)) {
		return false;
	}
	
	//Next, check to make sure the move is diagonal
	if ((abs(current_column - new_column)) != (abs(current_row - new_row))){
		(verbose) ? std::cout << "Bishops must move diagonally.\n" : std::cout << "";
		return false;
	}
	
	//Checks out, see if it's legal diagonal movement
	if (!legal_diagonal(board, new_row, new_column, current_row, current_column, verbose)){
		return false;
	}
	
	//Finally, does the move take the player's own piece
	if(takes_own_piece(board, new_location, verbose)) {
		return false;
	}
	return true;
}
