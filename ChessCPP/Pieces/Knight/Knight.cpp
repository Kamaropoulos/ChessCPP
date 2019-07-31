/**
 * @file Knight.cpp
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief Knight piece logic.
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Knight.h"

Knight::Knight(Position* pos, Color color) : Piece(pos, color, 3) {
}

vector<Position*> Knight::getAvailableMoves(Board* board) {
	vector<Position*> availableMoves;

	// Possible moves:
	// 2 Forward, 1 Left
	// 2 Forward, 1 Right
	// 2 Backwards, 1 Left
	// 2 Backwards, 1 Right
	// 2 Left, 1 Up
	// 2 Left, 1 Down
	// 2 Right, 1 Up
	// 2 Right, 1 Down

	Position* origin = new Position(this->position);

	Position* posToCheck = nullptr;

	vector<Position*> movesToCheck;

	// 2 Forward, 1 Left
	try {
		posToCheck = new Position(origin->getFile()-1, origin->getRank()+2);
		movesToCheck.push_back(posToCheck);
	}
	catch (...) {}


	// 2 Forward, 1 Right
	try {
		posToCheck = new Position(origin->getFile()+1, origin->getRank()+2);
		movesToCheck.push_back(posToCheck);
	}
	catch (...) {}

	// 2 Backwards, 1 Left
	try {
		posToCheck = new Position(origin->getFile()-1, origin->getRank()-2);
		movesToCheck.push_back(posToCheck);
	}
	catch (...) {}

	// 2 Backwards, 1 Right
	try {
		posToCheck = new Position(origin->getFile()+1, origin->getRank()-2);
		movesToCheck.push_back(posToCheck);
	}
	catch (...) {}

	// 2 Left, 1 Up
	try {
		posToCheck = new Position(origin->getFile()-2, origin->getRank()+1);
		movesToCheck.push_back(posToCheck);
	}
	catch (...) {}

	// 2 Left, 1 Down
	try {
		posToCheck = new Position(origin->getFile()-2, origin->getRank()-1);
		movesToCheck.push_back(posToCheck);
	}
	catch (...) {}

	// 2 Right, 1 Up
	try {
		posToCheck = new Position(origin->getFile()+2, origin->getRank()+1);
		movesToCheck.push_back(posToCheck);
	}
	catch (...) {}

	// 2 Right, 1 Down
	try {
		posToCheck = new Position(origin->getFile()+2, origin->getRank()-1);
		movesToCheck.push_back(posToCheck);
	}
	catch (...) {}

	for (auto move : movesToCheck) {
		MoveCheckResult res = this->_checkMove(move, board);
		if (res != CANT_MOVE) {
			availableMoves.push_back(move);
		}
	}

	return availableMoves;
}
