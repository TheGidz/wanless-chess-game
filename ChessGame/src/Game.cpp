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
	printf("Congratulations, your pawn has reached promotion.");
	do
	{
		printf("What kind of piece would you like to promote your pawn to?  (R)ook, (H)knight, (B)ishop, (Q)ueen");
		std::cin >> answer; // TODO: Replace all cins
		if (answer.size() > 1)
		{
			printf("Sorry, I didn't recognize that answer.  Please make sure it's only 1 character long.");
		}
		else
		{
			switch (toupper(answer.at(0))) // TODO: This could be streamlined
			{
			case 'R':
				delete masterBoard->board[endRow][endColumn];
				masterBoard->board[endRow][endColumn] = new Rook{m_playerTurn};
				validSelection = true;
				break;
			case 'H':
				delete masterBoard->board[endRow][endColumn];
				masterBoard->board[endRow][endColumn] = new Knight{m_playerTurn};
				validSelection = true;
				break;
			case 'B':
				delete masterBoard->board[endRow][endColumn];
				masterBoard->board[endRow][endColumn] = new Bishop{m_playerTurn};
				validSelection = true;
				break;
			case 'Q':
				delete masterBoard->board[endRow][endColumn];
				masterBoard->board[endRow][endColumn] = new Queen{m_playerTurn};
				validSelection = true;
				break;
			case 'K':
				printf("Nice try, but you cannot promote to King.  Please select a different answer.");
				break;
			default:
				printf("Sorry, I didn't recognize that answer.  Please make sure it's from the list of options.");
				break;
			}
		}
	} while (!validSelection);
	printf("You have promoted your pawn to a %s!", masterBoard->board[endRow][endColumn]->getPieceTypeString().c_str());
}

void Game::processMoveInput(int &row, int &column)
{
	std::string userInput;
	bool initialProcess = false;
	bool isDigitAlphaInput = false;
	bool bothInputsValidated = false;
	bool isDigitInRange = true;
	bool isAlphaInRange = true;
	char alphaChar = '0';
	char digitChar = '0';

	while (!bothInputsValidated)
	{
		while (!initialProcess)
		{
			std::cin >> userInput; // TODO: Get rid of CIN
			if (!(userInput.size() == 2))
			{
				printf("That was not a valid choice, your input needs to be exactly 2 characters long.  Please try again.");
			}
			else if (((isdigit(userInput.at(0))) && (isdigit(userInput.at(1)))) || ((isalpha(userInput.at(0))) && (isalpha(userInput.at(1)))))
			{
				printf("That was not a valid choice, your input needs to be exactly 1 letter, and 1 number.  Please try again.");
			}
			else
			{
				digitChar = (isdigit(userInput.at(0))) ? userInput.at(0) : userInput.at(1);
				alphaChar = toupper((isdigit(userInput.at(0))) ? userInput.at(1) : userInput.at(0));
				initialProcess = true;
			}
		}

		while (!isDigitAlphaInput)
		{
			row = digitChar - '0' - 1;

			if ((row > 7) || (row < 0)) // TODO: Consider not hardcoding this for different board sizes
			{
				printf("That was not a valid choice, your input needs contain a number between 1 and 8.\n");
				printf("You entered: %d\n", row);
				isDigitInRange = false;
			}

			column = alphaChar - 'A';
			if ((column > 7) || (column < 0)) // TODO: Consider not hardcoding this for different board sizes
			{
				printf("That was not a valid choice, your input needs contain a letter between A and H.\n");
				printf("You entered: %d\n", column);
				isAlphaInRange = false;
			}
			if (isAlphaInRange && isDigitInRange)
			{
				isDigitAlphaInput = true;
			}
		}
		if (isDigitAlphaInput && initialProcess)
		{
			bothInputsValidated = true;
		}
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
					printf("%s %s has taken %s %s", masterBoard->board[endRow][endColumn]->getOwnerString().c_str(),
						   masterBoard->board[endRow][endColumn]->getPieceTypeString().c_str(),
						   temp2->getOwnerString().c_str(),
						   temp2->getPieceTypeString().c_str());
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
			printf("Black is the winner!");
		}
		else if (m_playerTurn == Player::PLAYER_BLACK)
		{
			printf("White is the winner!");
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
					if (verbose)
					{
						printf("Your King is in check by: %s %s", masterBoard->board[i][j]->getOwnerString().c_str(), masterBoard->board[i][j]->getPieceTypeString().c_str());
					}
					return true;
				}
			}
		}
	}
	return false;
}

void Game::clearEnPassantRisks(GameBoard *masterBoard)
{
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
}

void Game::getNextMove(GameBoard *masterBoard)
{
	// At the start of the player's turn, clear all en passant risks
	clearEnPassantRisks(masterBoard);

	masterBoard->printBoard();
	bool validMove = false;
	while (!validMove)
	{
		int startRow{-1};
		int startColumn{-1};
		std::string player = (m_playerTurn == Player::PLAYER_WHITE) ? "White" : "Black"; // TODO: We have a function for this, but only for pieces

		bool selectionMade = false;
		while (!selectionMade)
		{
			printf("Please enter the ROW/COLUMN %s's piece to move is on: ", player.c_str());
			processMoveInput(startRow, startColumn);

			if (masterBoard->board[startRow][startColumn] == nullptr)
			{
				printf("Error: No piece selected.");
			}
			else if (masterBoard->board[startRow][startColumn]->getOwner() != m_playerTurn)
			{
				printf("Error: That is %s's piece, not yours.", masterBoard->board[startRow][startColumn]->getOwnerString().c_str());
			}
			else
			{
				selectionMade = true;
			}
		}

		printf("Please enter the ROW/COLUMN to move your %s to: ", masterBoard->board[startRow][startColumn]->getPieceTypeString().c_str());
		int endRow{-1};
		int endColumn{-1};
		processMoveInput(endRow, endColumn);

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
			printf("Invalid move.");
		}
	}
	return;
}

void Game::alternateTurn()
{
	if (m_playerTurn == Player::PLAYER_WHITE)
	{
		m_playerTurn = Player::PLAYER_BLACK;
		printf("It's now Black's turn.");
		return;
	}
	else if (m_playerTurn == Player::PLAYER_BLACK)
	{
		m_playerTurn = Player::PLAYER_WHITE;
		printf("It's now White's turn.");
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
		printf("The game has ended in checkmate!");
		return true;
	}
	else if (this->m_stalemate)
	{
		printf("The game has ended in a stalemate...");
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
