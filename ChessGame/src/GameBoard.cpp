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
	std::cout << "          A   B   C   D   E   F   G   H\n\n";

	for (size_t i = 0; i < m_boardSize; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (k == 1)
			{
				std::cout << "   " << i + 1 << "    ";
			}
			else
			{
				std::cout << "        ";
			}
			for (size_t j = 0; j < m_boardSize; j++)
			{
				switch (k)
				{
				case 0:
				case 2:
					if ((i + j) % 2 == 0)
					{
						for (int i = 1; i < 5; i++)
						{
							std::cout << '#';
						}
					}
					else
					{
						for (int i = 1; i < 5; i++)
						{
							std::cout << ' ';
						}
					}
					break;

				case 1:
					if ((i + j) % 2 == 0)
					{
						if (this->board[i][j] == nullptr)
						{
							std::cout << "####";
						}
						else
						{
							std::cout << '#' << *this->board[i][j] << '#';
						}
					}
					else
					{
						if (this->board[i][j] == nullptr)
						{
							std::cout << "    ";
						}
						else
						{
							std::cout << ' ' << *this->board[i][j] << ' ';
						}
					}
					break;
				}
			}
			std::cout << std::endl;
		}
	}
}