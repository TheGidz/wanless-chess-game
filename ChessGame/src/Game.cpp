#include "../inc/Game.h"

Game::Game() : m_playerTurn{Player::PLAYER_WHITE},
			   m_stalemate{false}
{
}

Game::~Game()
{
}

void Game::promotion(GameBoard *masterBoard, int endRow, int endColumn)
{
	std::string answer;
	bool validSelection = false;
	std::cout << "Congratulations, your pawn has reached promotion.\n";
	do
	{
		std::cout << "\n\nWhat kind of piece would you like to promote your pawn to?\n"
				  << "(R)ook, (H)knight, (B)ishop, (Q)ueen\n";
		std::cin >> answer;
		if (answer.size() == 1)
		{
			switch (toupper(answer.at(0)))
			{
			case 'R':
				delete masterBoard->board[endRow][endColumn];
				masterBoard->board[endRow][endColumn] = new Rook{m_playerTurn};
				std::cout << "You have promoted your pawn to a rook!\n";
				validSelection = true;
				break;
			case 'H':
				delete masterBoard->board[endRow][endColumn];
				masterBoard->board[endRow][endColumn] = new Knight{m_playerTurn};
				std::cout << "You have promoted your pawn to a knight!\n";
				validSelection = true;
				break;
			case 'B':
				delete masterBoard->board[endRow][endColumn];
				masterBoard->board[endRow][endColumn] = new Bishop{m_playerTurn};
				std::cout << "You have promoted your pawn to a bishop!\n";
				validSelection = true;
				break;
			case 'Q':
				delete masterBoard->board[endRow][endColumn];
				masterBoard->board[endRow][endColumn] = new Queen{m_playerTurn};
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
		}
		else
		{
			std::cout << "Sorry, I didn't recognize that answer.  Please make sure it's only 1 character long.\n";
		}
	} while (!validSelection);
}

void Game::processInput(int &row, int &column)
{
	std::string userInput;
	bool verify = false;
process:
	do
	{
		std::cin >> userInput;
		if (!(userInput.size() == 2))
		{
			std::cout << "That was not a valid choice, your input needs to be exactly 2 characters long.  Please try again.\n";
		}
		else if (((isdigit(userInput.at(0))) && (isdigit(userInput.at(1)))) || ((isalpha(userInput.at(0))) && (isalpha(userInput.at(1)))))
		{
			std::cout << "That was not a valid choice, your input needs to be exactly 1 letter, and 1 number.  Please try again.\n";
		}
		else
		{
			verify = true;
		}
	} while (!verify);
	verify = false;

	if (isdigit(userInput.at(0)))
	{
		row = userInput.at(0) - '0';
		row -= 1;
	}
	else if (isdigit(userInput.at(1)))
	{
		row = userInput.at(1) - '0';
		row -= 1;
	}
	if ((row > 7) || (row < 0))
	{
		std::cout << "That was not a valid choice, your input needs contain a number between 1 and 8.\n";
		verify = false;
		goto process;
	}

	userInput.at(0) = toupper(userInput.at(0));
	userInput.at(1) = toupper(userInput.at(1));
	if (((userInput.at(0)) == 'A') || ((userInput.at(1)) == 'A'))
	{
		column = 0;
	}
	else if (((userInput.at(0)) == 'B') || ((userInput.at(1)) == 'B'))
	{
		column = 1;
	}
	else if (((userInput.at(0)) == 'C') || ((userInput.at(1)) == 'C'))
	{
		column = 2;
	}
	else if (((userInput.at(0)) == 'D') || ((userInput.at(1)) == 'D'))
	{
		column = 3;
	}
	else if (((userInput.at(0)) == 'E') || ((userInput.at(1)) == 'E'))
	{
		column = 4;
	}
	else if (((userInput.at(0)) == 'F') || ((userInput.at(1)) == 'F'))
	{
		column = 5;
	}
	else if (((userInput.at(0)) == 'G') || ((userInput.at(1)) == 'G'))
	{
		column = 6;
	}
	else if (((userInput.at(0)) == 'H') || ((userInput.at(1)) == 'H'))
	{
		column = 7;
	}
	else
	{
		std::cout << "That was not a valid choice, your input needs contain a letter between A and H.\n";
		verify = false;
		goto process;
	}
}

bool Game::castle(GameBoard *masterBoard, int startRow, int startColumn, int endRow, int endColumn)
{
	// The selected piece is a king
	if (masterBoard->board[startRow][startColumn]->getPieceType() == GamePieceType::GAME_PIECE_KING)
	{
		// The King is not currently in check
		if (!inCheck(m_playerTurn, masterBoard, false))
		{
			// has_moved for the King is false
			if (masterBoard->board[startRow][startColumn]->getHasMoved() == false)
			{
				// The king is moving 2 spaces to the right
				if ((startRow == endRow) && (startColumn == (endColumn - 2)))
				{
					// hasMoved for the Rook on column H is false
					if ((masterBoard->board[startRow][7] != nullptr) && (masterBoard->board[startRow][7]->getHasMoved() == false))
					{
						// There are no pieces between the rook and the king
						if ((masterBoard->board[startRow][4] == nullptr) && (masterBoard->board[startRow][5] == nullptr))
						{
							// The King would not go into check on any square between his current location, and his destination.
							masterBoard->board[startRow][4] = masterBoard->board[startRow][startColumn];
							masterBoard->board[startRow][5] = masterBoard->board[startRow][startColumn];
							if (!inCheck(m_playerTurn, masterBoard, false))
							{
								// Move and zero out all the appropriate pieces
								masterBoard->board[startRow][startColumn] = 0;
								masterBoard->board[startRow][4] = masterBoard->board[startRow][7];
								masterBoard->board[startRow][7] = 0;

								// set the king and the rook's hasMoved to true
								masterBoard->board[startRow][4]->setHasMoved(true);
								masterBoard->board[startRow][5]->setHasMoved(true);
								return true;
							}
							else
							{
								masterBoard->board[startRow][4] = 0;
								masterBoard->board[startRow][5] = 0;
							}
						}
					}
				}
				// The king is moving 2 different spaces left
				if ((startRow == endRow) && (startColumn == (endColumn + 2)))
				{
					// hasMoved for the Rook on column A is false
					if ((masterBoard->board[startRow][0] != nullptr) && (masterBoard->board[startRow][0]->getHasMoved() == false))
					{
						// There are no pieces between the rook and the king
						if ((masterBoard->board[startRow][2] == nullptr) && (masterBoard->board[startRow][1] == nullptr))
						{
							// The King would not go into check on any square between his current location, and his destination.
							masterBoard->board[startRow][2] = masterBoard->board[startRow][startColumn];
							masterBoard->board[startRow][1] = masterBoard->board[startRow][startColumn];
							if (!inCheck(m_playerTurn, masterBoard, false))
							{
								// Move and zero out all the appropriate pieces
								masterBoard->board[startRow][3] = 0;
								masterBoard->board[startRow][2] = masterBoard->board[startRow][0];
								masterBoard->board[startRow][0] = 0;

								// set the king and the rook's hasMoved to true
								masterBoard->board[startRow][1]->setHasMoved(true);
								masterBoard->board[startRow][2]->setHasMoved(true);
								return true;
							}
							else
							{
								masterBoard->board[startRow][2] = 0;
								masterBoard->board[startRow][1] = 0;
							}
						}
					}
				}
			}
		}
	}
	// If any of the above criteria doesn't check out, return false.
	return false;
}

bool Game::makeMove(GameBoard *masterBoard, int startRow, int startColumn, int endRow, int endColumn, bool forKeeps, bool verbose)
{
	// Be ready to save the move, we'll need to put it back later if 'forKeeps' is false or if the move puts us in check.
	GamePiece *temp1{0};
	GamePiece *temp2{0};

	// Check if that move is legal for the given piece, save the current locations of the pieces, and put the piece there
	if (masterBoard->board[startRow][startColumn]->moveIsLegal(*masterBoard->board, endRow, endColumn, verbose))
	{
		temp1 = masterBoard->board[startRow][startColumn];
		temp2 = masterBoard->board[endRow][endColumn];

		masterBoard->board[endRow][endColumn] = masterBoard->board[startRow][startColumn];
		masterBoard->board[startRow][startColumn] = 0;
		// if the move we just made would put the player into check, undo the move and return false
		if (inCheck(m_playerTurn, masterBoard, verbose))
		{
			masterBoard->board[startRow][startColumn] = temp1;
			masterBoard->board[endRow][endColumn] = temp2;
			return false;
			// Else, this is a legal move that doesn't put us into check.
		}
		else
		{
			// Check for promotion
			if ((masterBoard->board[endRow][endColumn]->getPieceType() == GamePieceType::GAME_PIECE_PAWN) && ((endRow == 0) || (endRow == 7)))
			{
				promotion(masterBoard, endRow, endColumn);
			}
			// If this is set to forKeeps, this piece is no longer in its starting position, return true and delete any pieces captured
			if (forKeeps)
			{
				masterBoard->board[endRow][endColumn]->setHasMoved(true);
				if (temp2 != nullptr)
				{
					std::cout << *masterBoard->board[endRow][endColumn] << " has taken " << *temp2 << std::endl;
					delete temp2;
				}
				// Otherwise, if it's just a hypothetical move, put everything back, and clear en passant.
			}
			else
			{
				masterBoard->board[startRow][startColumn] = temp1;
				masterBoard->board[endRow][endColumn] = temp2;
				masterBoard->board[startRow][startColumn]->setEnPassant(false);
			}
			return true;
		}
	}
	else
	{
		return false;
	}
}

bool Game::checkmate(Player m_playerTurn, GameBoard *masterBoard)
{

	// for every piece the current player controls
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			if ((masterBoard->board[i][j] != nullptr) && (masterBoard->board[i][j]->getOwner() == m_playerTurn))
			{
				// check all legal moves that piece has
				for (size_t k = 0; k < 8; k++)
				{
					for (size_t l = 0; l < 8; l++)
					{
						// if there are any legal moves the current piece can make, it's not a stalemate
						if ((masterBoard->board[i][j]->moveIsLegal(*masterBoard->board, k, l, false)))
						{
							if (makeMove(masterBoard, i, j, k, l, false, false))
							{
								// If it makes it here, we still have legal moves that won't put us into check. Return false.
								return false;
							}
						}
					}
				}
			}
		}
	}
	// if we've made it our of that for loop nest, then there are no legal moves that don't put us into check.
	// If we're not in check right now, then we're in a stalemate
	if (!inCheck(m_playerTurn, masterBoard, false))
	{
		this->m_stalemate = true;
	}
	else
	{
		// otherwise we're in checkmate.  Declare a winner.
		if (m_playerTurn == Player::PLAYER_WHITE)
		{
			std::cout << "Black is the winner!\n";
		}
		else if (m_playerTurn == Player::PLAYER_BLACK)
		{
			std::cout << "White is the winner!\n";
		}
		return true;
	}
	return false;
}

bool Game::inCheck(Player m_playerTurn, GameBoard *masterBoard, bool verbose)
{

	// Get current player's king's location
	size_t kingColumn = -1;
	size_t kingRow = -1;

	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			if ((masterBoard->board[i][j] != nullptr) && (masterBoard->board[i][j]->getOwner() == m_playerTurn) && (masterBoard->board[i][j]->getPieceType() == GamePieceType::GAME_PIECE_KING))
			{
				kingRow = i;
				kingColumn = j;
			}
		}
	}

	// for all enemy pieces on the board
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			if ((masterBoard->board[i][j] != nullptr) && (masterBoard->board[i][j]->getOwner() != m_playerTurn))
			{
				// check if king's location is a legal move, if it is king is in check
				if (masterBoard->board[i][j]->moveIsLegal(*masterBoard->board, kingRow, kingColumn, false))
				{
					(verbose) ? std::cout << "Your King is in check by: " << *masterBoard->board[i][j] << std::endl : std::cout << "";
					return true;
				}
			}
		}
	}
	return false;
}

void Game::getNextMove(GameBoard *masterBoard)
{
	// At the start of the player's turn, clear all en passant risks
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((masterBoard->board[i][j] != nullptr) && (masterBoard->board[i][j]->getOwner() == m_playerTurn) && (masterBoard->board[i][j]->getPieceType() == GamePieceType::GAME_PIECE_PAWN))
			{
				masterBoard->board[i][j]->setEnPassant(false);
			}
		}
	}

	bool validMove = false;
	do
	{
	make_selection: // TODO: Remove goto, this is nasty
		masterBoard->printBoard();
		std::cout << "\nPlease enter the ROW/COLUMN " << m_playerTurn << "'s piece to move is on: ";
		int startRow{-1};
		int startColumn{-1};
		processInput(startRow, startColumn);

		if (masterBoard->board[startRow][startColumn] == nullptr)
		{
			std::cout << "Error: No piece selected.\n";
			goto make_selection;
		}
		else if (masterBoard->board[startRow][startColumn]->getOwner() != m_playerTurn)
		{
			std::cout << "Error: That is " << masterBoard->board[startRow][startColumn]->getOwner() << "'s piece, not yours.\n";
			goto make_selection;
		}

		std::cout << "Please enter the ROW/COLUMN to move your " << masterBoard->board[startRow][startColumn]->getPieceType() << " to: ";
		int endRow{-1};
		int endColumn{-1};
		processInput(endRow, endColumn);

		// Check if this move is castling, which has its own ruleset
		if (castle(masterBoard, startRow, startColumn, endRow, endColumn))
		{
			validMove = true;
		}
		// otherwise, if that move is legal for the given piece, make the move
		else if (makeMove(masterBoard, startRow, startColumn, endRow, endColumn, true, true))
		{
			validMove = true;
		}
		else
		{
			std::cout << "Invalid move.\n";
		}
	} while (!validMove);
	return;
}

void Game::alternateTurn()
{
	if (m_playerTurn == Player::PLAYER_WHITE)
	{
		m_playerTurn = Player::PLAYER_BLACK;
		std::cout << "It's now Black's turn.\n";
		return;
	}
	else if (m_playerTurn == Player::PLAYER_BLACK)
	{
		m_playerTurn = Player::PLAYER_WHITE;
		std::cout << "It's now White's turn.\n";
		return;
	}
	else
	{
		std::cerr << "Error in calculating turn, invalid input.\n";
		return;
	}
}

bool Game::gameOver()
{
	// Check for checkmate, stalemate, or forfeit.  Return false if none of those are true.
	if (checkmate(m_playerTurn, &masterBoard))
	{
		std::cout << "\n\n			The game has ended in checkmate!\n"
				  << std::endl;
		return true;
	}
	else if (this->m_stalemate)
	{
		std::cout << "\n\n			The game has ended in a stalemate...\n"
				  << std::endl;
		return true;
	}
	return false;
}

void Game::start()
{
	do
	{
		getNextMove(&masterBoard);
		alternateTurn();
	} while (!gameOver());
	masterBoard.printBoard();
}
