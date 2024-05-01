#include "../inc/GamePiece.h"

GamePiece::GamePiece() : m_owner{Player::PLAYER_COUNT},
						 m_pieceType{GamePieceType::GAME_PIECE_COUNT},
						 m_hasMoved{false},
						 m_enPassant{false},
						 m_pieceTypeChar('X')
{
	std::cerr << "An error has occured, and a GamePiece object without a kind or owner associated has somehow been created.\n";
}

GamePiece::GamePiece(Player player, GamePieceType pieceType) : m_owner{player},
															   m_pieceType{pieceType},
															   m_hasMoved{false},
															   m_enPassant{false},
															   m_pieceTypeChar(getPieceTypeChar())
{
}

GamePiece::~GamePiece()
{
	std::cout << "\t\t" << *this << " has been removed from the board.\n";
}

bool GamePiece::moveIsLegal(GamePiece *board[8], int column, int row, bool verbose)
{
	return false;
}

bool GamePiece::getEnPassant()
{
	return m_enPassant;
}

void GamePiece::setEnPassant(bool setting)
{
	m_enPassant = setting;
	return;
}

bool GamePiece::getHasMoved()
{
	return m_hasMoved;
}

void GamePiece::setHasMoved(bool setting)
{
	m_hasMoved = setting;
	return;
}

GamePieceType GamePiece::getPieceType()
{
	return m_pieceType;
}

char GamePiece::getPieceTypeChar()
{
	char retVal = '0';
	switch (m_pieceType)
	{
	case GAME_PIECE_BISHOP:
		retVal = 'B';
		break;
	case GAME_PIECE_QUEEN:
		retVal = 'Q';
		break;
	case GAME_PIECE_KING:
		retVal = 'K';
		break;
	case GAME_PIECE_KNIGHT:
		retVal = 'H';
		break;
	case GAME_PIECE_PAWN:
		retVal = 'P';
		break;
	case GAME_PIECE_ROOK:
		retVal = 'R';
		break;
	default:
		break;
	}
	return retVal;
}

Player GamePiece::getOwner()
{
	return m_owner;
}

bool GamePiece::inBounds(int row, int column, bool verbose)
{
	if (row < 0 || row > 7 || column < 0 || column > 7)
	{
		(verbose) ? std::cout << "That move is out of bounds.\n" : std::cout << "";
		return false;
	}
	return true;
}

bool GamePiece::doesMove(int new_column, int new_row, int current_column, int current_row, bool verbose)
{
	if ((new_column == current_column) && (new_row == current_row))
	{
		(verbose) ? std::cout << "The selected piece must move.\n" : std::cout << "";
		return false;
	}
	return true;
}

bool GamePiece::takesOwnPiece(GamePiece *board[8], int new_location, bool verbose)
{
	if ((board[new_location] == nullptr) || (board[new_location]->m_owner != this->m_owner))
	{
		// does not take own piece
		return false;
	}
	else
	{
		(verbose) ? std::cout << "You cannot take your own pieces.\n" : std::cout << "";
		// takes own piece
		return true;
	}
}

void GamePiece::findOnBoard(GamePiece *board[8], int &current_location, int &current_row, int &current_column)
{
	for (size_t i = 0; i < (8 * 8); i++)
	{
		if (board[i] == this)
		{
			current_location = i;
		}
	}

	// set the columns and rows to the appropriate values based on the flattened array that was passed in.
	current_row = current_location / 8;
	current_column = current_location - (current_row * 8);
}

bool GamePiece::legalDiagonal(GamePiece *board[8], int new_row, int new_column, int current_row, int current_column, bool verbose)
{
	if ((new_column > current_column) && (new_row > current_row))
	{
		// moving down/right
		// check for collision along the way
		int j = new_column - 1;
		for (int i = new_row - 1; i > current_row; i--)
		{
			int temp_location = (i * 8) + j;
			if (board[temp_location] != nullptr)
			{
				(verbose) ? std::cout << "There was something in this piece's way.\n" : std::cout << "";
				return false;
			}
			j--;
		}
	}
	else if ((new_column < current_column) && (new_row > current_row))
	{
		// moving down/left
		// check for collision along the way
		int j = new_column + 1;
		for (int i = new_row - 1; i > current_row; i--)
		{
			int temp_location = (i * 8) + j;
			if (board[temp_location] != nullptr)
			{
				(verbose) ? std::cout << "There was something in this piece's way.\n" : std::cout << "";
				return false;
			}
			j++;
		}
	}
	else if ((new_column < current_column) && (new_row < current_row))
	{
		// moving up/left
		// check for collision along the way
		int j = new_column + 1;
		for (int i = new_row + 1; i < current_row; i++)
		{
			int temp_location = (i * 8) + j;
			if (board[temp_location] != nullptr)
			{
				(verbose) ? std::cout << "There was something in this piece's way.\n" : std::cout << "";
				return false;
			}
			j++;
		}
	}
	else if ((new_column > current_column) && (new_row < current_row))
	{
		// moving up/right
		// check for collision along the way
		int j = new_column - 1;
		for (int i = new_row + 1; i < current_row; i++)
		{
			int temp_location = (i * 8) + j;
			if (board[temp_location] != nullptr)
			{
				(verbose) ? std::cout << "There was something in this piece's way.\n" : std::cout << "";
				return false;
			}
			j--;
		}
	}
	return true;
}

bool GamePiece::legalStraight(GamePiece *board[8], int new_row, int new_column, int current_row, int current_column, bool verbose)
{
	if ((new_column == current_column) && (new_row != current_row))
	{
		if (new_row < current_row)
		{
			for (int i = new_row + 1; i < current_row; i++)
			{
				int temp_location = (i * 8) + new_column;
				if (board[temp_location] != nullptr)
				{
					(verbose) ? std::cout << "There was something in this piece's way.\n" : std::cout << "";
					return false;
				}
			}
		}
		else if (new_row > current_row)
		{
			for (int i = new_row - 1; i > current_row; i--)
			{
				int temp_location = (i * 8) + new_column;
				if (board[temp_location] != nullptr)
				{
					(verbose) ? std::cout << "There was something in this piece's way.\n" : std::cout << "";
					return false;
				}
			}
		}

		// Then check vertical movement to see if anything is obstructing the path
	}
	else if ((new_column != current_column) && (new_row == current_row))
	{
		if (new_column < current_column)
		{
			for (int i = new_column + 1; i < current_column; i++)
			{
				int temp_location = (new_row * 8) + i;
				if (board[temp_location] != nullptr)
				{
					(verbose) ? std::cout << "There was something in this piece's way.\n" : std::cout << "";
					return false;
				}
			}
		}
		else if (new_column > current_column)
		{
			for (int i = new_column - 1; i > current_column; i--)
			{
				int temp_location = (new_row * 8) + i;
				if (board[temp_location] != nullptr)
				{
					(verbose) ? std::cout << "There was something in this piece's way.\n" : std::cout << "";
					return false;
				}
			}
		}
	}
	else
	{
		(verbose) ? std::cout << "There was something in this piece's way.\n" : std::cout << "";
		return false;
	}
	return true;
}

void GamePiece::printPiece(std::ostream &os) const
{
	char owner = (m_owner == Player::PLAYER_WHITE) ? 'W' : 'B';
	os << owner << m_pieceTypeChar;
	return;
}

std::ostream &operator<<(std::ostream &os, const GamePiece &piece)
{
	piece.printPiece(os);
	return os;
}