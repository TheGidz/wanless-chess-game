#ifndef GAME_BOARD_H
#define GAME_BOARD_H
#include <string>
#include <iostream>

#include "../pieces/inc/Pawn.h"
#include "../pieces/inc/Rook.h"
#include "../pieces/inc/Knight.h"
#include "../pieces/inc/Bishop.h"
#include "../pieces/inc/Queen.h"
#include "../pieces/inc/King.h"
#include "Enums.hpp"

class GameBoard
{
public:
	static const size_t m_boardSize{8};
	GameBoard();
	~GameBoard();
	void printBoard();

private:
	GamePiece *board[m_boardSize][m_boardSize];
	friend class Game;
};

#endif // GAME_BOARD_H