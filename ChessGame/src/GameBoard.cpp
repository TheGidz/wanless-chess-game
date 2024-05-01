#include "../inc/GameBoard.h"

GameBoard::GameBoard()
{
	for (size_t i = 0; i < m_boardSize; i++)
	{
		for (size_t j = 0; j < m_boardSize; j++)
		{
			board[i][j] = 0;
		}
	}

	//	//Black pieces
	for (size_t i = 0; i < m_boardSize; i++)
	{
		board[6][i] = new Pawn{Player::PLAYER_BLACK};
	}
	board[7][0] = new Rook{Player::PLAYER_BLACK};
	board[7][1] = new Knight{Player::PLAYER_BLACK};
	board[7][2] = new Bishop{Player::PLAYER_BLACK};
	board[7][3] = new King{Player::PLAYER_BLACK};
	board[7][4] = new Queen{Player::PLAYER_BLACK};
	board[7][5] = new Bishop{Player::PLAYER_BLACK};
	board[7][6] = new Knight{Player::PLAYER_BLACK};
	board[7][7] = new Rook{Player::PLAYER_BLACK};

	//	//White pieces
	for (size_t i = 0; i < m_boardSize; i++)
	{
		board[1][i] = new Pawn{Player::PLAYER_WHITE};
	}
	board[0][0] = new Rook{Player::PLAYER_WHITE};
	board[0][1] = new Knight{Player::PLAYER_WHITE};
	board[0][2] = new Bishop{Player::PLAYER_WHITE};
	board[0][3] = new King{Player::PLAYER_WHITE};
	board[0][4] = new Queen{Player::PLAYER_WHITE};
	board[0][5] = new Bishop{Player::PLAYER_WHITE};
	board[0][6] = new Knight{Player::PLAYER_WHITE};
	board[0][7] = new Rook{Player::PLAYER_WHITE};
}

GameBoard::~GameBoard()
{
	for (size_t i = 0; i < m_boardSize; i++)
	{
		for (size_t j = 0; j < m_boardSize; j++)
		{
			delete board[i][j];
			board[i][j] = 0;
		}
	}
}

void GameBoard::printBoard()
{
	printf("\033[2J");
	// Show the column letters
	uint8_t letterPos = 11;
	for (size_t squareIndex = 1; squareIndex <= m_boardSize; squareIndex++)
	{
		char charToPrint = 64;
		printf("\033[39\033[%d;%dH%c", 0, letterPos + ((squareIndex - 1) * m_squareWidth), (charToPrint + squareIndex));
	}

	// Show the row numbers
	uint8_t numberPos = 4;
	for (size_t squareIndex = 1; squareIndex <= m_boardSize; squareIndex++)
	{
		char charToPrint = '0';
		printf("\033[%d;%dH%c", numberPos + ((squareIndex - 1) * m_squareHeight), 0, (charToPrint + squareIndex));
	}

	// Print the board by squares
	for (size_t squareHorizontalIndex = 1; squareHorizontalIndex <= m_boardSize; squareHorizontalIndex++)
	{
		for (size_t squareVerticalIndex = 1; squareVerticalIndex <= m_boardSize; squareVerticalIndex++)
		{
			// Set the square colour
			uint8_t printColourFore = 36;
			if ((squareVerticalIndex + squareHorizontalIndex) % 2 == 1)
			{
				printColourFore = 31;
			} // Red
			else
			{
				printColourFore = 37;
			} // White

			for (size_t squareHeight = 1; squareHeight <= m_squareHeight; squareHeight++)
			{
				for (size_t squareWidth = 1; squareWidth <= m_squareWidth; squareWidth++)
				{
					size_t rowOffset = ((squareHorizontalIndex - 1) * m_squareHeight) + m_borderHeight;
					size_t columnOffset = ((squareVerticalIndex - 1) * m_squareWidth) + m_borderWidth;
					printf("\033[%dm\033[%d;%dH#", printColourFore, (rowOffset + squareHeight), (columnOffset + squareWidth));
				}
			}
		}

		// Print the pieces which are on the board
		for (size_t boardHorizInx = 0; boardHorizInx < m_boardSize; boardHorizInx++)
		{
			for (size_t boardVertInx = 0; boardVertInx < m_boardSize; boardVertInx++)
			{
				if (this->board[boardHorizInx][boardVertInx] != nullptr)
				{
					char piece = (this->board[boardHorizInx][boardVertInx]->getPieceTypeChar());
					uint8_t pieceColour = (this->board[boardHorizInx][boardVertInx]->getOwner() == Player::PLAYER_WHITE) ? 37 : 31;

					size_t rowOffset = ((boardHorizInx + 1) * m_squareHeight) + m_borderHeight - (m_squareHeight / 2);
					size_t columnOffset = ((boardVertInx + 1) * m_squareWidth) + m_borderWidth - (m_squareHeight / 2);

					printf("\033[%dm\033[%d;%dH%c", pieceColour, (rowOffset), (columnOffset), piece);
				}
			}
		}
	}
	printf("\033[37m\033[%d;%dH", m_boardSize * m_squareHeight + m_borderHeight * 2, 0);
}