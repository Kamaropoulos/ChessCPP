/**
 * @file Pawn.cpp
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief Pawn piece logic.
 * @version 0.1
 * @date 2019-07-06
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Pawn.h"

Pawn::Pawn(Position* pos, Color color) : Piece(pos, color, 1) {
}

vector<Position*> Pawn::getAvailableMoves(Board* board) {
	vector<Position*> availableMoves;
	// Movement direction: Increase rank if white, decrease rank if black.
	bool direction = (this->getColor() == WHITE) ? 1 : 0; // 0: Decrease rank, 1: Increase rank

	// Possible moves:
	// - If first move, 1 forward and 2 forward if empty
	// - Diagonically to the left and right if enemy piece
	Position* posToCheck = new Position(this->position);

	// if Piece is white, we move upwards in ranks
	if (this->getColor() == WHITE) {
		try {
			// Check one forward
			posToCheck->gotoTop();
			// If piece can move to square (move or take)
			MoveResult res = this->_checkMove(posToCheck, board);
			if ((res != CANT_MOVE)) {
				// Push as available move
				availableMoves.push_back(new Position(posToCheck));
			}
			// Reset posToCheck
			posToCheck->set(this->getPosition()->toString());
		} catch (...) {}
		
		// Check if it can move two forward
		if (!this->hasMoved()) {
			try {
				// If piece can move to square (move or take)
				posToCheck->setRank(posToCheck->getRank() + 2);
				MoveResult res = this->_checkMove(posToCheck, board);
				if ((res != CANT_MOVE)) {
					// Push as available move
					availableMoves.push_back(new Position(posToCheck));
				}
				// Reset posToCheck
				posToCheck->set(this->getPosition()->toString());
			} catch(...) {}
		}

		// Check take positions

		try {
			// Top left
			posToCheck->gotoTopLeft();
			// If piece can move to square (move or take)
			MoveResult res = this->_checkMove(posToCheck, board);
			if ((res == CAN_TAKE)) {
				// Push as available move
				availableMoves.push_back(new Position(posToCheck));
			}
			// Reset posToCheck
			posToCheck->set(this->getPosition()->toString());
		} catch(...) {}

		try {
			// Top right
			posToCheck->gotoTopRight();
			// If piece can move to square (move or take)
			MoveResult res = this->_checkMove(posToCheck, board);
			if ((res == CAN_TAKE)) {
				// Push as available move
				availableMoves.push_back(new Position(posToCheck));
			}
			// Reset posToCheck
			posToCheck->set(this->getPosition()->toString());
		} catch (...) {}
	}
	else {
		// else, if it's black, we move downwards in ranks
		try {
			// Check one forward
			posToCheck->gotoBottom();
			// If piece can move to square (move or take)
			MoveResult res = this->_checkMove(posToCheck, board);
			if ((res != CANT_MOVE)) {
				// Push as available move
				availableMoves.push_back(new Position(posToCheck));
			}
			// Reset posToCheck
			posToCheck->set(this->getPosition()->toString());
		} catch (...) {}

		// Check if it can move two forward
		if (!this->hasMoved()) {
			try {
				// If piece can move to square (move or take)
				posToCheck->setRank(posToCheck->getRank() - 2);
				MoveResult res = this->_checkMove(posToCheck, board);
				if ((res != CANT_MOVE)) {
					// Push as available move
					availableMoves.push_back(new Position(posToCheck));
				}
				// Reset posToCheck
				posToCheck->set(this->getPosition()->toString());
			} catch (...) {}
		}

		// Check take positions

		try {
			// Forward left
			posToCheck->gotoBottomLeft();
			// If piece can move to square (move or take)
			MoveResult res = this->_checkMove(posToCheck, board);
			if ((res == CAN_TAKE)) {
				// Push as available move
				availableMoves.push_back(new Position(posToCheck));
			}
			// Reset posToCheck
			posToCheck->set(this->getPosition()->toString());
		} catch (...) {}

		try {
			// Forward right
			posToCheck->gotoBottomRight();
			// If piece can move to square (move or take)
			MoveResult res = this->_checkMove(posToCheck, board);
			if ((res == CAN_TAKE)) {
				// Push as available move
				availableMoves.push_back(new Position(posToCheck));
			}
			// Reset posToCheck
			posToCheck->set(this->getPosition()->toString());
		} catch (...) {}
	}

	return availableMoves;
}
