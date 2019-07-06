/**
 * @file Game.cpp
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief High-level game overview and management.
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Game.h"

/**
 * @brief Construct a new Game:: Game object
 * 
 * It creates a new board and the pieces for the two players.
 */
Game::Game() {
	this->board = new Board();

	string* files = new string[9]{ "", "a", "b", "c", "d", "e", "f", "g", "h" };
	for (int rank = 1; rank <= 8; ++rank) {
		for (int file = 1; file <= 8; ++file) {
			Square* sq = this->board->getSquare(files[file] + to_string(rank));
			if (sq != nullptr) {
				if (this->board->getSquare(files[file] + to_string(rank))->hasPiece()) {
					cout << "Square " << files[file] << to_string(rank) << " is " << ((this->board->getSquare(files[file] + to_string(rank))->getColor() == BLACK) ? "black" : "white") << " and holds a " << ((this->board->getSquare(files[file] + to_string(rank))->getPiece()->color == BLACK) ? "black " : "white ") << this->board->getSquare(files[file] + to_string(rank))->getPiece()->pieceName() << endl;
				}
				else {
					cout << "Square " << files[file] << to_string(rank) << " is " << ((this->board->getSquare(files[file] + to_string(rank))->getColor() == BLACK) ? "black" : "white") << " and it's empty" << endl;
				}
			}
			else {
				cout << "Square " << files[file] << to_string(rank) << " is null" << endl;
			}
		}
	}
}
