#ifndef GAME_H
#define GAME_H
#include "GameBoard.h"

class Game
{
public:
	Game();
	~Game();
	void start();
	void alternateTurn();
	bool gameOver();
	void clearEnPassantRisks(GameBoard *masterBoard);
	void getNextMove(GameBoard *board);
	void processMoveInput(int &row, int &column);
	bool makeMove(GameBoard *masterBoard, int startRow, int startColumn, int endRow, int endColumn, bool forKeeps, bool verbose);
	bool inCheck(Player playerTurn, GameBoard *masterBoard, bool verbose);
	bool checkmate(Player playerTurn, GameBoard *masterBoard);
	bool castle(GameBoard *masterBoard, int startRow, int startColumn, int endRow, int endColumn);
	void promotion(GameBoard *masterBoard, int endRow, int endColumn);
	GameBoard masterBoard;

protected:
	Player m_playerTurn;
	bool m_stalemate;
};

#endif // GAME_H
