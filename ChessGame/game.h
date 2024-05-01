#ifndef GAME_HclTabCtrl
#define GAME_H
#include "game_board.h"

class game
{
public:
	game();
	~game();
	void start();
	void alternateTurn();
	bool game_over();
	void getNextMove(game_board *board);
	void processInput (int &row, int &column);
	bool make_move(game_board *masterBoard, int start_row, int start_column, int end_row, int end_column, bool for_keeps, bool verbose);
	bool in_check(Player playerTurn, game_board *masterBoard, bool verbose);
	bool checkmate(Player playerTurn, game_board *masterBoard);
	bool castle(game_board *masterBoard, int start_row, int start_column, int end_row, int end_column);
	void promotion(game_board *masterBoard, int end_row, int end_column);
	game_board masterBoard;
	
protected:
	Player m_playerTurn;
	bool m_stalemate;
	
};

#endif // GAME_H
