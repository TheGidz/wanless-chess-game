#include "queen.h"

queen::queen(Player owner)
: game_piece {owner, GamePieceType::GAME_PIECE_QUEEN}
{
}

queen::~queen()
{
}

bool queen::move_is_legal(game_piece* board[8], int new_row, int new_column, bool verbose) {
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
	
	//if the movement is horizontal/vertical, apply horizontal/vertical movement logic as with rooks
	if ((new_column == current_column) || (new_row == current_row)) {
		//if the movement is horizontal/vertical, apply horizontal/vertical movement logic as with rooks
		if (!legal_straight(board, new_row, new_column, current_row, current_column, verbose)) {
			return false;
		}
	} else	
	//Next, check to make sure the move is diagonal
	if ((abs(current_column - new_column)) == (abs(current_row - new_row))){
		//if the movement is diagonal, apply diagonal movement logic as with bishops
		if (!legal_diagonal(board, new_row, new_column, current_row, current_column, verbose)){
			return false;
		}
	} else {
		(verbose) ? std::cout << "Queens must move straight, or diagonally.\n" : std::cout << "";
		return false;
	}
	
	//Finally, let's make sure that we don't try to take our own piece
	if(takes_own_piece(board, new_location, verbose)) {
			return false;
	}
	return true;
}