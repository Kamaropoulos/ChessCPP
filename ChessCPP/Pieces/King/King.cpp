/**
 * @file King.cpp
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief King piece logic
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "King.h"

King::King(Position* pos, Color color) : Piece(pos, color, 0) {
}

vector<Position*> King::getAvailableMoves(Board* board) {
	vector<Position*> availableMoves;

	// Possible moves:
	// up
	// down
	// left
	// right
	// up right
	// up left
	// down right
	// down left

	Position* origin = new Position(this->position);

	Position* posToCheck = nullptr;

	vector<Position*> movesToCheck;

	// up
	try {
		posToCheck = new Position(origin->getFile(), origin->getRank() + 1);
		movesToCheck.push_back(posToCheck);
	}
	catch (...) {}

	// down
	try {
		posToCheck = new Position(origin->getFile(), origin->getRank() - 1);
		movesToCheck.push_back(posToCheck);
	}
	catch (...) {}

	// left
	try {
		posToCheck = new Position(origin->getFile() - 1, origin->getRank());
		movesToCheck.push_back(posToCheck);
	}
	catch (...) {}

	// right
	try {
		posToCheck = new Position(origin->getFile() + 1 , origin->getRank());
		movesToCheck.push_back(posToCheck);
	}
	catch (...) {}

	// up right
	try {
		posToCheck = new Position(origin->getFile() + 1, origin->getRank() + 1);
		movesToCheck.push_back(posToCheck);
	}
	catch (...) {}

	// up left
	try {
		posToCheck = new Position(origin->getFile() - 1, origin->getRank() + 1);
		movesToCheck.push_back(posToCheck);
	}
	catch (...) {}

	// down right
	try {
		posToCheck = new Position(origin->getFile() + 1, origin->getRank() - 1);
		movesToCheck.push_back(posToCheck);
	}
	catch (...) {}

	// down left
	try {
		posToCheck = new Position(origin->getFile() - 1, origin->getRank() - 1);
		movesToCheck.push_back(posToCheck);
	}
	catch (...) {}

	for (auto move : movesToCheck) {
		MoveCheckResult res = this->_checkMove(move, board);
		if (res != CANT_MOVE) {
			availableMoves.push_back(move);
		}
	}

	for (auto move : availableMoves) {
		cout << move->toString() << endl;
	}

	return availableMoves;
}
