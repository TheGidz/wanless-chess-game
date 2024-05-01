//Ari Wanless 2022 playable chess board.
//This program includes all elements for a two-human-player chess game.  There is no AI to play against.
//User input is taken in the form of LETTER/NUMBER pairs (or NUMBER/LETTER PAIRS) for the piece to select, and where to move it to.
//This program checks for each pieces legal moves, including castling, en passant, check, checkmate, and stalemate.

#include <iostream>
#include "game_board.h"
#include "game.h"



int main () {
	game masterGame;
	game_board mainBoard;
	masterGame.start();
	std::cout << "Thanks for playing!\n";	
	
	return 0;
}