#include "game_piece.h"

game_piece::game_piece() :
	m_owner{Player::PLAYER_COUNT},
	m_pieceType{GamePieceType::GAME_PIECE_COUNT},
	m_hasMoved{false},
	m_enPassant{false}
{
	std::cerr << "An error has occured, and a game_piece object without a kind or owner associated has somehow been created.\n";
}

game_piece::game_piece(Player player, GamePieceType pieceType) :
	m_owner{player},
	m_pieceType{pieceType},
	m_hasMoved{false},
	m_enPassant{false}
{

}

game_piece::~game_piece()
{
	std::cout << "\t\t" << *this << " has been removed from the board.\n";
}

bool game_piece::move_is_legal(game_piece* board[8], int column, int row, bool verbose) {
	return false;
}

bool game_piece::get_en_passant() {
	return this->m_enPassant;
}

void game_piece::set_en_passant(bool setting) {
	this->m_enPassant = setting;
	return;
}

bool game_piece::get_has_moved() {
	return this->m_hasMoved;
}

void game_piece::set_has_moved(bool setting) {
	this->m_hasMoved = setting;
	return;
}

GamePieceType game_piece::getPieceType() {
	return this->m_pieceType;
}

Player game_piece::get_owner() {
	return this->m_owner;
}

bool game_piece::in_bounds (int row, int column, bool verbose) {
	if (row < 0 || row > 7 || column < 0 || column > 7) {
		(verbose) ? std::cout << "That move is out of bounds.\n" : std::cout << "";
		return false;
	}
	return true;
}

bool game_piece::does_move(int new_column, int new_row, int current_column, int current_row, bool verbose) {
	if ((new_column == current_column) && (new_row == current_row)) {
		(verbose) ? std::cout << "The selected piece must move.\n" : std::cout << "";
		return false;
	}
	return true;
}

bool game_piece::takes_own_piece(game_piece* board[8], int new_location, bool verbose) {
	if ((board[new_location] == nullptr) || (board[new_location]->m_owner != this->m_owner)) {
		//does not take own piece
		return false;
	} else {
		(verbose) ? std::cout << "You cannot take your own pieces.\n" : std::cout << "";
		//takes own piece
		return true;
	}
}

void game_piece::find_on_board(game_piece* board[8], int &current_location, int &current_row, int &current_column) {
	for (size_t i = 0; i < (8*8); i++) {
		if (board[i] == this) {
			current_location = i;
		}
	}
	
	//set the columns and rows to the appropriate values based on the flattened array that was passed in.
	current_row = current_location/8;
	current_column = current_location - (current_row*8);
}

bool game_piece::legal_diagonal(game_piece* board[8], int new_row, int new_column, int current_row, int current_column, bool verbose) {
if ((new_column > current_column) && (new_row > current_row)) {
		//moving down/right
		//check for collision along the way
		int j = new_column-1;
		for (int i = new_row-1; i > current_row; i--) {
			int temp_location = (i*8) + j;
			if (board[temp_location] != nullptr) {
				(verbose) ? std::cout << "There was something in this piece's way.\n" : std::cout << "";
				return false;
			}
			j--;
		}
	} else if ((new_column < current_column) && (new_row > current_row)) {
		//moving down/left
		//check for collision along the way
		int j = new_column+1;
		for (int i = new_row-1; i > current_row; i--) {
			int temp_location = (i*8) + j;
			if (board[temp_location] != nullptr) {
				(verbose) ? std::cout << "There was something in this piece's way.\n" : std::cout << "";
				return false;
			}
			j++;
		}
	} else if ((new_column < current_column) && (new_row < current_row)) {
		//moving up/left
		//check for collision along the way
		int j = new_column+1;
		for (int i = new_row+1; i < current_row; i++) {
			int temp_location = (i*8) + j;
			if (board[temp_location] != nullptr) {
				(verbose) ? std::cout << "There was something in this piece's way.\n" : std::cout << "";
				return false;
			}
			j++;
		}
	} else if ((new_column > current_column) && (new_row < current_row)) {
		//moving up/right
		//check for collision along the way
		int j = new_column-1;
		for (int i = new_row+1; i < current_row; i++) {
			int temp_location = (i*8) + j;
			if (board[temp_location] != nullptr) {
				(verbose) ? std::cout << "There was something in this piece's way.\n" : std::cout << "";
				return false;
			}
			j--;
		}
	}
	return true;
}

bool game_piece::legal_straight(game_piece* board[8], int new_row, int new_column, int current_row, int current_column, bool verbose) {
	if ((new_column == current_column) && (new_row != current_row)) {
		if (new_row < current_row) {
			for (int i = new_row+1; i < current_row; i++) {
				int temp_location = (i*8) + new_column;
				if (board[temp_location] != nullptr) {
					(verbose) ? std::cout << "There was something in this piece's way.\n" : std::cout << "";
					return false;
				}
			}
		} else if (new_row > current_row) {
			for (int i = new_row-1; i > current_row; i--) {
				int temp_location = (i*8) + new_column;
				if (board[temp_location] != nullptr) {
					(verbose) ? std::cout << "There was something in this piece's way.\n" : std::cout << "";
					return false;
				}
			}
		}

	//Then check vertical movement to see if anything is obstructing the path
	} else if ((new_column != current_column) && (new_row == current_row)) {
		if (new_column < current_column) {
			for (int i = new_column+1; i < current_column; i++) {
				int temp_location = (new_row*8) + i;
				if (board[temp_location] != nullptr) {
					(verbose) ? std::cout << "There was something in this piece's way.\n" : std::cout << "";
					return false;
				}
			}
		} else if (new_column > current_column) {
			for (int i = new_column-1; i > current_column; i--) {
				int temp_location = (new_row*8) + i;
				if (board[temp_location] != nullptr) {
					(verbose) ? std::cout << "There was something in this piece's way.\n" : std::cout << "";
					return false;
				}
			}
		}
	} else {
		(verbose) ? std::cout << "There was something in this piece's way.\n" : std::cout << "";
		return false;
	}
	return true;
}

void game_piece::print_piece(std::ostream &os) const {
//	if (this == nullptr) {
//		os << 'X';
//		return;
//	}
	char owner = (m_owner == Player::PLAYER_WHITE) ? 'W' : 'B';
	char pieceType = GamePieceType::GAME_PIECE_COUNT;
	switch (m_pieceType)
	{
		case GamePieceType::GAME_PIECE_PAWN:
		{
			pieceType = 'P';
			break;
		}
		case GamePieceType::GAME_PIECE_ROOK:
		{
			pieceType = 'R';
			break;
		}
		case GamePieceType::GAME_PIECE_KNIGHT:
		{
			pieceType = 'H';
			break;
		}
		case GamePieceType::GAME_PIECE_BISHOP:
		{
			pieceType = 'B';
			break;
		}
		case GamePieceType::GAME_PIECE_QUEEN:
		{
			pieceType = 'Q';
			break;
		}
		case GamePieceType::GAME_PIECE_KING:
		{
			pieceType = 'K';
			break;
		}
		default:
		{
			//ERROR CONDITION
			pieceType = 'X';
			break;
		}
	}
    os << owner << pieceType;
	return;
}

std::ostream &operator<<(std::ostream &os, const game_piece &piece) {
    piece.print_piece(os);
    return os;
}