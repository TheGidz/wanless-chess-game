#include "pawn.h"

pawn::pawn(Player owner)
: game_piece {owner, GamePieceType::GAME_PIECE_PAWN}
{
}

pawn::~pawn()
{
}

bool pawn::move_is_legal(game_piece* board[8], int new_row, int new_column, bool verbose) {
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
	
	//Next let's make sure that we don't try to take our own piece
	if(takes_own_piece(board, new_location, verbose)) {
			return false;
	}
	
	//movement logic for white pawns
	if (this->get_owner() == 'W') {
		//First move as a double move logic
		if ((new_column == current_column) && (new_row == (current_row+2))) {
			if (this->get_has_moved() == false) {
				if (board[new_location] == nullptr) { 
					//Double move exposes pawn to en passant
					this->set_en_passant(true);
					return true;
				}
			} else {
				(verbose) ? std::cout << "Pawns can only double move on their first move.\n" : std::cout << "";
			}
		}
		if ((new_column == current_column) && (new_row == (current_row+1))) {
			if (board[new_location] == nullptr) { 
				return true;
			}
			(verbose) ? std::cout << "This space is not empty, and pawns cannot take pieces this way.\n" : std::cout << "";
		}
		//Logic to detect legal taking pieces
		if (((new_column == current_column +1) || (new_column == current_column -1))
		&& (new_row == current_row+1) && (board[new_location] != nullptr)
		&& (board[new_location]->get_owner() != this->get_owner())) {
			return true;
		}
		//Logic to detect legal en passant
		if (((new_column == current_column +1) || (new_column == current_column -1)) && (new_row == current_row+1)
		&& (board[new_location] == nullptr) && (board[new_location-8] != nullptr)
		&& (board[new_location-8]->get_owner() != this->get_owner())
		&& (board[new_location-8]->getPieceType() == GamePieceType::GAME_PIECE_PAWN) && (board[new_location-8]->get_en_passant() == true)) {
			//Deleting a piece from here causes problems, so instead we will move the piece that is being taken
			//to where other logic can delete it for us cleanly.
			board[new_location] = board[new_location-8];
			board[new_location-8] = 0;
			return true;
		}
	}
	
	//movement logic for black pawns
	if (this->get_owner() == 'B') {
		//First move is a double move
		if ((new_column == current_column) && (new_row == (current_row-2))) {
			if (this->get_has_moved() == false) {
				if (board[new_location] == nullptr) { 
					//Double move exposes pawn to en passant
					this->set_en_passant(true);
					return true;
				}
			} else {
				(verbose) ? std::cout << "Pawns can only double move on their first move.\n" : std::cout << "";
			}
		}
		if ((new_column == current_column) && (new_row == (current_row-1))) {
			if (board[new_location] == nullptr) { 
				return true;
			}
			(verbose) ? std::cout << "This space is not empty, and this piece cannot take pieces this way.\n" : std::cout << "";
		}
		//Logic to detect legal taking pieces
		if (((new_column == current_column +1) || (new_column == current_column -1)) && (new_row == current_row-1)
		&& (board[new_location] != nullptr) && (board[new_location]->get_owner() != this->get_owner())) {
			return true;
		}
		//Logic to detect legal en passant
		if (((new_column == current_column +1) || (new_column == current_column -1)) && (new_row == current_row-1)
		&& (board[new_location] == nullptr) && (board[new_location+8] != nullptr)
		&& (board[new_location+8]->get_owner() != this->get_owner())
		&& (board[new_location+8]->getPieceType() == 'P') && (board[new_location+8]->get_en_passant() == true)) {
			//Deleting a piece from here causes problems, so instead we will move the piece that is being taken
			//to where other logic can delete it for us cleanly.
			board[new_location] = board[new_location+8];
			board[new_location+8] = 0;
			return true;
		}
	}
	return false;
}
