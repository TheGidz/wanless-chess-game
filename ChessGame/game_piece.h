#ifndef GAME_PIECE_H_
#define GAME_PIECE_H_
#include <string>
#include <iostream>
#include "Enums.hpp"

class game_piece
{
private:
	game_piece();
	const Player m_owner;
	const GamePieceType m_pieceType;
	bool m_hasMoved;
	bool m_enPassant;
	
public:
	game_piece(Player owner, GamePieceType pieceType);
	virtual ~game_piece();
	virtual bool move_is_legal(game_piece* board[8], int column, int row, bool verbose);
	
	bool legal_diagonal(game_piece* board[8], int new_row, int new_column, int current_row, int current_column, bool verbose);
	bool legal_straight(game_piece* board[8], int new_row, int new_column, int current_row, int current_column, bool verbose);
	bool get_en_passant();
	bool get_has_moved();
	GamePieceType getPieceType();
	Player get_owner();
	void set_en_passant(bool setting);
	void set_has_moved(bool setting);
	void print_piece(std::ostream &os) const;
	bool in_bounds (int row, int column, bool verbose);
	bool does_move(int new_column, int new_row, int current_column, int current_row, bool verbose);
	bool takes_own_piece(game_piece* board[8], int new_location, bool verbose);
	void find_on_board(game_piece* board[8], int &current_location, int &current_row, int &current_column);
	
	friend std::ostream &operator<<(std::ostream &os, const game_piece &piece);
};

#endif // GAME_PIECE_H_
