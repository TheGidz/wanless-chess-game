#include "game.h"

game::game() :
	m_playerTurn{Player::PLAYER_WHITE},
	m_stalemate{false}
{
}

game::~game()
{
}

void game::promotion(game_board *masterBoard, int end_row, int end_column) {
	std::string answer;
	bool validSelection = false;
	std::cout << "Congratulations, your pawn has reached promotion.\n";
	do {
		std::cout  << "\n\nWhat kind of piece would you like to promote your pawn to?\n"
				   << "(R)ook, (H)knight, (B)ishop, (Q)ueen\n";
		std::cin >> answer;
		if (answer.size() == 1) {
			switch (toupper(answer.at(0)))
			{
				case 'R':
					delete masterBoard->board[end_row][end_column];
					masterBoard->board[end_row][end_column] = new rook{m_playerTurn};
					std::cout << "You have promoted your pawn to a rook!\n";
					validSelection = true;
					break;
				case 'H':
					delete masterBoard->board[end_row][end_column];
					masterBoard->board[end_row][end_column] = new knight{m_playerTurn};
					std::cout << "You have promoted your pawn to a knight!\n";
					validSelection = true;
					break;
				case 'B':
					delete masterBoard->board[end_row][end_column];
					masterBoard->board[end_row][end_column] = new bishop{m_playerTurn};
					std::cout << "You have promoted your pawn to a bishop!\n";
					validSelection = true;
					break;
				case 'Q':
					delete masterBoard->board[end_row][end_column];
					masterBoard->board[end_row][end_column] = new queen{m_playerTurn};
					std::cout << "You have promoted your pawn to a queen!\n";
					validSelection = true;
					break;
				case 'K':
					std::cout << "Nice try, but you cannot promote to King.  Please select a different answer.\n";
					break;
				default:
					std::cout << "Sorry, I didn't recognize that answer.  Please make sure it's from the list of options.\n";
					break;
			}
		} else {
			std::cout << "Sorry, I didn't recognize that answer.  Please make sure it's only 1 character long.\n";
		}
	} while (!validSelection);
}

void game::processInput (int &row, int &column) {
	std::string userInput;
	bool verify = false;
	process:
	do {
		std::cin >> userInput;
		if (!(userInput.size() == 2)) {
			std::cout << "That was not a valid choice, your input needs to be exactly 2 characters long.  Please try again.\n";
		} else if (((isdigit(userInput.at(0))) && (isdigit(userInput.at(1)))) || ((isalpha(userInput.at(0))) && (isalpha(userInput.at(1))))) {
			std::cout << "That was not a valid choice, your input needs to be exactly 1 letter, and 1 number.  Please try again.\n";
		} else {
			verify = true;
		}
	} while (!verify);
	verify  = false;
	
	if (isdigit(userInput.at(0))) {
		row = userInput.at(0) - '0';
		row -=1;
	} else if (isdigit(userInput.at(1))) {
		row = userInput.at(1) - '0';
		row-=1;
	}
	if ((row > 7) || (row < 0)) {
		std::cout << "That was not a valid choice, your input needs contain a number between 1 and 8.\n";
		verify = false;
		goto process;
	}

	userInput.at(0) = toupper(userInput.at(0));
	userInput.at(1) = toupper(userInput.at(1));
	if (((userInput.at(0)) == 'A' ) || ((userInput.at(1)) == 'A' )) {
			column = 0;
	} else if (((userInput.at(0)) == 'B' ) || ((userInput.at(1)) == 'B' )) {
			column = 1;
	} else if (((userInput.at(0)) == 'C' ) || ((userInput.at(1)) == 'C' )) {
			column = 2;
	} else if (((userInput.at(0)) == 'D' ) || ((userInput.at(1)) == 'D' )) {
			column = 3;
	} else if (((userInput.at(0)) == 'E' ) || ((userInput.at(1)) == 'E' )) {
			column = 4;
	} else if (((userInput.at(0)) == 'F' ) || ((userInput.at(1)) == 'F' )) {
			column = 5;
	} else if (((userInput.at(0)) == 'G' ) || ((userInput.at(1)) == 'G' )) {
			column = 6;
	} else if (((userInput.at(0)) == 'H' ) || ((userInput.at(1)) == 'H' )) {
			column = 7;
	} else {
		std::cout << "That was not a valid choice, your input needs contain a letter between A and H.\n";
		verify = false;
		goto process;
	}
}

bool game::castle(game_board *masterBoard, int start_row, int start_column, int end_row, int end_column) {
	//The selected piece is a king
	if (masterBoard->board[start_row][start_column]->getPieceType() == GamePieceType::GAME_PIECE_KING) {
		//The King is not currently in check
		if (!in_check(m_playerTurn, masterBoard, false)){
			//has_moved for the King is false
			if (masterBoard->board[start_row][start_column]->get_has_moved() == false) {
				//The king is moving 2 spaces to the right
				if ((start_row == end_row) && (start_column == (end_column - 2))){
					//has_moved for the Rook on column H is false
					if ((masterBoard->board[start_row][7] != nullptr) && (masterBoard->board[start_row][7]->get_has_moved() == false)) {
						//There are no pieces between the rook and the king
						if ((masterBoard->board[start_row][4] == nullptr) && (masterBoard->board[start_row][5] == nullptr)) {
							//The King would not go into check on any square between his current location, and his destination.
							masterBoard->board[start_row][4] = masterBoard->board[start_row][start_column];
							masterBoard->board[start_row][5] = masterBoard->board[start_row][start_column];
							if (!in_check(m_playerTurn, masterBoard, false)) {
								//Move and zero out all the appropriate pieces
								masterBoard->board[start_row][start_column] = 0;
								masterBoard->board[start_row][4] = masterBoard->board[start_row][7];
								masterBoard->board[start_row][7] = 0;
								
								//set the king and the rook's has_moved to true
								masterBoard->board[start_row][4]->set_has_moved(true);
								masterBoard->board[start_row][5]->set_has_moved(true);
								return true;
							} else {
								masterBoard->board[start_row][4] = 0;
								masterBoard->board[start_row][5] = 0;
							}
						}
					}
				}
				//The king is moving 2 different spaces left
				if ((start_row == end_row) && (start_column == (end_column + 2))){
					//has_moved for the Rook on column A is false
					if ((masterBoard->board[start_row][0] != nullptr) && (masterBoard->board[start_row][0]->get_has_moved() == false)) {
						//There are no pieces between the rook and the king
						if ((masterBoard->board[start_row][2] == nullptr) && (masterBoard->board[start_row][1] == nullptr)) {
							//The King would not go into check on any square between his current location, and his destination.
							masterBoard->board[start_row][2] = masterBoard->board[start_row][start_column];
							masterBoard->board[start_row][1] = masterBoard->board[start_row][start_column];
							if (!in_check(m_playerTurn, masterBoard, false)) {
								//Move and zero out all the appropriate pieces
								masterBoard->board[start_row][3] = 0;
								masterBoard->board[start_row][2] = masterBoard->board[start_row][0];
								masterBoard->board[start_row][0] = 0;
								
								//set the king and the rook's has_moved to true
								masterBoard->board[start_row][1]->set_has_moved(true);
								masterBoard->board[start_row][2]->set_has_moved(true);
								return true;
							} else {
								masterBoard->board[start_row][2] = 0;
								masterBoard->board[start_row][1] = 0;
							}
						}
					}
				}
			}
		}
	}
	//If any of the above criteria doesn't check out, return false.
	return false;
}

bool game::make_move(game_board *masterBoard, int start_row, int start_column, int end_row, int end_column, bool for_keeps, bool verbose) {
	//Be ready to save the move, we'll need to put it back later if 'for_keeps' is false or if the move puts us in check.
	game_piece *temp1{0};
	game_piece *temp2{0};
	
	//Check if that move is legal for the given piece, save the current locations of the pieces, and put the piece there
	if (masterBoard->board[start_row][start_column]->move_is_legal(*masterBoard->board, end_row, end_column, verbose)) {
		temp1 = masterBoard->board[start_row][start_column];
		temp2 = masterBoard->board[end_row][end_column];
		
		masterBoard->board[end_row][end_column] = masterBoard->board[start_row][start_column];
		masterBoard->board[start_row][start_column] = 0;
		//if the move we just made would put the player into check, undo the move and return false
		if (in_check(m_playerTurn, masterBoard, verbose)) {
			masterBoard->board[start_row][start_column] = temp1;
			masterBoard->board[end_row][end_column] = temp2;
			return false;
		//Else, this is a legal move that doesn't put us into check.
		} else {
			//Check for promotion
			if ((masterBoard->board[end_row][end_column]->getPieceType() == GamePieceType::GAME_PIECE_PAWN) && ((end_row == 0) || (end_row ==7))) {
				promotion(masterBoard, end_row, end_column);
			}
			//If this is set to for_keeps, this piece is no longer in its starting position, return true and delete any pieces captured
			if (for_keeps) {
				masterBoard->board[end_row][end_column]->set_has_moved(true);
				if (temp2 != nullptr){
					std::cout << *masterBoard->board[end_row][end_column] << " has taken " << *temp2 << std::endl;
					delete temp2;
				}
			//Otherwise, if it's just a hypothetical move, put everything back, and clear en passant.
			} else {
				masterBoard->board[start_row][start_column] = temp1;
				masterBoard->board[end_row][end_column] = temp2;
				masterBoard->board[start_row][start_column]->set_en_passant(false);
			}
			return true;
		}
	} else {
		return false;
	}
}

bool game::checkmate(Player m_playerTurn, game_board *masterBoard){
	
	//for every piece the current player controls
	for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {
			if ((masterBoard->board[i][j] != nullptr) && (masterBoard->board[i][j]->get_owner() == m_playerTurn)) {
				//check all legal moves that piece has
				for (size_t k = 0; k < 8; k++) {
					for (size_t l = 0; l < 8; l++) {
						//if there are any legal moves the current piece can make, it's not a stalemate
						if ((masterBoard->board[i][j]->move_is_legal(*masterBoard->board, k, l, false))) {
							if (make_move(masterBoard, i, j, k, l, false, false)) {
								//If it makes it here, we still have legal moves that won't put us into check. Return false.
								return false;
							}
						}
					}
				}
			}
		}
	}
	//if we've made it our of that for loop nest, then there are no legal moves that don't put us into check.
	//If we're not in check right now, then we're in a stalemate
	if(!in_check(m_playerTurn, masterBoard, false)) {
		this->m_stalemate = true;
	} else {
	//otherwise we're in checkmate.  Declare a winner.
		if (m_playerTurn == Player::PLAYER_WHITE) {
			std::cout << "Black is the winner!\n";
		} else if (m_playerTurn == Player::PLAYER_BLACK) {
			std::cout << "White is the winner!\n";
		}
		return true;
	}
	return false;
}

bool game::in_check(Player m_playerTurn, game_board *masterBoard, bool verbose){
	
	//Get current player's king's location
	size_t king_column = -1;
	size_t king_row = -1;

	for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {
			if ((masterBoard->board[i][j] != nullptr)
			 && (masterBoard->board[i][j]->get_owner() == m_playerTurn)
			 && (masterBoard->board[i][j]->getPieceType() == GamePieceType::GAME_PIECE_KING))
			{
				king_row = i;
				king_column = j;
			}
		}
	}	
	
	//for all enemy pieces on the board
	for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {
			if ((masterBoard->board[i][j] != nullptr) && (masterBoard->board[i][j]->get_owner() != m_playerTurn)) {
				//check if king's location is a legal move, if it is king is in check
				if (masterBoard->board[i][j]->move_is_legal(*masterBoard->board, king_row, king_column, false)) {
					(verbose) ? std::cout << "Your King is in check by: " << *masterBoard->board[i][j] << std::endl : std::cout << "";
					return true;
				}
			}
		}
	}
	return false;
}

void game::getNextMove(game_board *masterBoard){
	//At the start of the player's turn, clear all en passant risks
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((masterBoard->board[i][j] != nullptr)
			 && (masterBoard->board[i][j]->get_owner() == m_playerTurn)
			 && (masterBoard->board[i][j]->getPieceType() == GamePieceType::GAME_PIECE_PAWN))
			 {
				 masterBoard->board[i][j]->set_en_passant(false);
			 }

		}
	}

	bool validMove = false;
	do
	{
		make_selection:
		masterBoard->print_board();
		std::cout << "\nPlease enter the ROW/COLUMN " << m_playerTurn << "'s piece to move is on: ";
		int start_row {-1};
		int start_column {-1};
		processInput(start_row, start_column);

		if (masterBoard->board[start_row][start_column] == nullptr)
		{
			std::cout << "Error: No piece selected.\n";
			goto make_selection;
		}
		else if (masterBoard->board[start_row][start_column]->get_owner() != m_playerTurn)
		{
			std::cout << "Error: That is " << masterBoard->board[start_row][start_column]->get_owner() << "'s piece, not yours.\n";
			goto make_selection;
		}
		
		std::cout << "Please enter the ROW/COLUMN to move your " << masterBoard->board[start_row][start_column]->getPieceType() << " to: ";
		int end_row {-1};
		int end_column {-1};
		processInput(end_row, end_column);
		
		//Check if this move is castling, which has its own ruleset
		if (castle(masterBoard, start_row, start_column, end_row, end_column))
		{
			validMove = true;
		}
		//otherwise, if that move is legal for the given piece, make the move
		else if (make_move(masterBoard, start_row, start_column, end_row, end_column, true, true))
		{
			validMove = true;
		} else
		{
			std::cout << "Invalid move.\n";
		}
	} while (!validMove);
	return;
}

void game::alternateTurn(){
	if (m_playerTurn == Player::PLAYER_WHITE)
	{
		m_playerTurn = Player::PLAYER_BLACK;
		std::cout << "It's now Black's turn.\n";
		return;
	} else if (m_playerTurn == Player::PLAYER_BLACK)
		{
		m_playerTurn = Player::PLAYER_WHITE;
		std::cout << "It's now White's turn.\n";
		return;
	} else {
		std::cerr << "Error in calculating turn, invalid input.\n";
		return;
	}
}

bool game::game_over() {
	//Check for checkmate, stalemate, or forfeit.  Return false if none of those are true.
	if (checkmate(m_playerTurn, &masterBoard)) {
		std::cout << "\n\n			The game has ended in checkmate!\n" << std::endl;
		return true;
	} else if (this->m_stalemate) {
		std::cout << "\n\n			The game has ended in a stalemate...\n" << std::endl;
		return true;
	}
	return false;
}

void game::start() {
	do {
		getNextMove(&masterBoard);
		alternateTurn();
	} while (!game_over());
	masterBoard.print_board();
}
