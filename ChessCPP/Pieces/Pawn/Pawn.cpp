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

Pawn::Pawn(Position* pos, Color color) : Piece(pos, color) {
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
		// Check one forward
		posToCheck->gotoTop();
		// If piece can move to square (move or take)
		MoveCheckResult res = this->_checkMove(posToCheck, board);
		if ((res != CANT_MOVE)) {
			// Push as available move
			availableMoves.push_back(new Position(posToCheck));
		}
		// Reset posToCheck
		posToCheck->set(this->getPosition()->toString());

		// Check if it can move two forward
		if (!this->hasMoved()) {
			// If piece can move to square (move or take)
			posToCheck->setRank(posToCheck->getRank() + 2);
			MoveCheckResult res = this->_checkMove(posToCheck, board);
			if ((res != CANT_MOVE)) {
				// Push as available move
				availableMoves.push_back(new Position(posToCheck));
			}
			// Reset posToCheck
			posToCheck->set(this->getPosition()->toString());
		}

		// Check take positions

		// Top left
		posToCheck->gotoTopLeft();
		// If piece can move to square (move or take)
		res = this->_checkMove(posToCheck, board);
		if ((res == CAN_TAKE)) {
			// Push as available move
			availableMoves.push_back(new Position(posToCheck));
		}
		// Reset posToCheck
		posToCheck->set(this->getPosition()->toString());

		// Top right
		posToCheck->gotoTopRight();
		// If piece can move to square (move or take)
		res = this->_checkMove(posToCheck, board);
		if ((res == CAN_TAKE)) {
			// Push as available move
			availableMoves.push_back(new Position(posToCheck));
		}
		// Reset posToCheck
		posToCheck->set(this->getPosition()->toString());
	}

	return availableMoves;
}
