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
	game->movePiece(2, "g2", "f2");
}