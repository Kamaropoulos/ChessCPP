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

Game::Game() {
	this->board = new Board();

	string* files = new string[9]{ "", "a", "b", "c", "d", "e", "f", "g", "h" };
	for (int rank = 1; rank <= 8; ++rank) {
		for (int file = 1; file <= 8; ++file) {
			Square* sq = this->board->getSquare(files[file] + to_string(rank));
			if (sq != nullptr) {
				if (this->board->getSquare(files[file] + to_string(rank))->hasPiece()) {
					cout << files[file] << to_string(rank) << " is " << this->board->getSquare(files[file] + to_string(rank))->getPiece()->pieceName() << endl;
				}
				else {
					cout << files[file] << to_string(rank) << " is empty" << endl;
				}
			}
			else {
				cout << files[file] << to_string(rank) << " is null" << endl;
			}
		}
	}
}