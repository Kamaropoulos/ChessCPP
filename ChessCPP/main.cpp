/**
 * @file main.cpp
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief ChessCPP entry file.
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Game/Game.h"

/**
 * @brief Entry point.
 * 
 * @return int 
 */
int main() {
	Game* game = new Game();
	game->movePiece(1, "b2", "b3");
	game->movePiece(2, "f7", "f6");
	game->movePiece(1, "e2", "e4");
	game->movePiece(2, "f6", "f5");
	game->movePiece(1, "a2", "a4");
	game->movePiece(2, "f5", "e4");
	game->movePiece(1, "d2", "d3");
	game->movePiece(2, "g7", "g5");
	game->movePiece(1, "d3", "e4");
	game->movePiece(2, "g5", "g4");
	game->movePiece(1, "f2", "f3");
	game->movePiece(2, "a7", "a6");
	game->movePiece(1, "f3", "g4");
	cout << game->getScore().first << " - " << game->getScore().second << endl;
}