#include "knight.h"

knight::knight(Player owner)
: game_piece {owner, GamePieceType::GAME_PIECE_KNIGHT}
{
}

knight::~knight()
{
}

bool knight::move_is_legal(game_piece* board[8], int new_row, int new_column, bool verbose) {
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
	
	//movement logic.  Lots of conditions to check in order to make any of the 8 L shaped movements accepted by Knight movement.
	if ((((new_column == current_column + 1) || (new_column == current_column - 1)) && ((new_row == (current_row-2)) || (new_row == current_row+2)))
	|| (((new_column == current_column + 2) || (new_column == current_column - 2)) && ((new_row == (current_row-1)) || (new_row == current_row+1)))) {
		//So long as this move doesn't take the player's own piece, it's legal
		if(!takes_own_piece(board, new_location, verbose)) {
			return true;
		}
	}
	return false;
}
