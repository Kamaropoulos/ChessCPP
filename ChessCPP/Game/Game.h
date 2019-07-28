/**
 * @file Game.h
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief High-level game overview and management.
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once
#include <string>
#include "../Board/Board.h"

using namespace std;

/**
 * @brief Game class
 * 
 */
class Game {
private:
	Board* board;
	int scorePlayer1;
	int scorePlayer2;
	unsigned char playerTurn;
	void _printStatus();
	void _printBoard();

public:
	/**
	 * @brief Construct a new Game object
	 * 
	 */
	Game();

	bool movePiece(int player, string origin, string destination);
};
