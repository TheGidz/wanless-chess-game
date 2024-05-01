#ifndef GAME_BOARD_H
#define GAME_BOARD_H
#include <string>
#include <iostream>

#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "Enums.hpp"


class game_board
{
public:
	static const size_t m_boardSize {8};
	game_board();
	~game_board();
	void print_board();
	
private:
	game_piece* board[m_boardSize][m_boardSize];
	friend class game;

};

#endif // GAME_BOARD_H
