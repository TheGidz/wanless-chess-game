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
	static const uint8_t m_boardSize{8};
	static const uint8_t m_squareHeight{3};
	static const uint8_t m_squareWidth{3};
	static const uint8_t m_borderHeight{2};
	static const uint8_t m_borderWidth{8};
	GameBoard();
	~GameBoard();
	void printBoard();

private:
	GamePiece *board[m_boardSize][m_boardSize];
	friend class Game;
};

#endif // GAME_BOARD_H
