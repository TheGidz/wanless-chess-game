#include "king.h"

king::king(Player owner)
: game_piece {owner, GamePieceType::GAME_PIECE_KING}
{
}

king::~king()
{
}

bool king::move_is_legal(game_piece* board[8], int new_row, int new_column, bool verbose) {
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
	
	//movement logic
	if (((new_column == current_column) || (new_column == current_column + 1) || (new_column == current_column -1))
	&& ((new_row == current_row) || (new_row == current_row+1) ||(new_row == current_row-1))) {
		//As long as it doesn't take the player's own piece, it's legal.
		//Rules for castling cannot be calculated here, and thus are found in game.cpp
		if (!takes_own_piece(board, new_location, verbose)) {
			return true;
		}
	}
	return false;
}