/**
 * @file Bishop.cpp
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief Bishop piece logic.
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Bishop.h"

Bishop::Bishop(Position* pos, Color color) : Piece(pos, color, 3) {
}

vector<Position*> Bishop::getAvailableMoves(Board* board) {
	vector<Position*> availableMoves;

	// Possible moves:
	// Diagonically up left, up right, bottom left, bottom right
	// up to the first enemy piece or before the first friendly piece
	// or until the end of the board (or when goto throws)
	Position* posToCheck = new Position(this->position);

	// Check up right (increase ranks)
	try {
		// Up to the end of the board
		int file = this->getPosition()->getFile();
		int rank = this->getPosition()->getRank();
		while ((++rank <= 8) && (++file <= 8)) {
			posToCheck->gotoTopRight();
			// If piece can move to square
			MoveCheckResult res = this->_checkMove(posToCheck, board);
			if (res == CAN_MOVE) {
				availableMoves.push_back(new Position(posToCheck));
			}
			else if (res == CAN_TAKE) {
				// If can take, we add this move to the available ones
				// but we can't move any further so we break the loop
				availableMoves.push_back(new Position(posToCheck));
				break;
			}
			else {
				// If can't move it means there's a friendly piece.
				// Break loop
				break;
			}
		}
	}
	catch (...) {}

	// Reset posToCheck
	posToCheck->set(this->getPosition()->toString());

	// Check up left (increase ranks)
	try {
		// Up to the end of the board
		int file = this->getPosition()->getFile();
		int rank = this->getPosition()->getRank();
		while ((++rank <= 8) && (--file <= 8)) {
			posToCheck->gotoTopLeft();
			// If piece can move to square
			MoveCheckResult res = this->_checkMove(posToCheck, board);
			if (res == CAN_MOVE) {
				availableMoves.push_back(new Position(posToCheck));
			}
			else if (res == CAN_TAKE) {
				// If can take, we add this move to the available ones
				// but we can't move any further so we break the loop
				availableMoves.push_back(new Position(posToCheck));
				break;
			}
			else {
				// If can't move it means there's a friendly piece.
				// Break loop
				break;
			}
		}
	}
	catch (...) {}

	// Reset posToCheck
	posToCheck->set(this->getPosition()->toString());

	// Check down right (increase ranks)
	try {
		// Up to the end of the board
		int file = this->getPosition()->getFile();
		int rank = this->getPosition()->getRank();
		while ((--rank <= 8) && (++file <= 8)) {
			posToCheck->gotoBottomRight();
			// If piece can move to square
			MoveCheckResult res = this->_checkMove(posToCheck, board);
			if (res == CAN_MOVE) {
				availableMoves.push_back(new Position(posToCheck));
			}
			else if (res == CAN_TAKE) {
				// If can take, we add this move to the available ones
				// but we can't move any further so we break the loop
				availableMoves.push_back(new Position(posToCheck));
				break;
			}
			else {
				// If can't move it means there's a friendly piece.
				// Break loop
				break;
			}
		}
	}
	catch (...) {}

	// Reset posToCheck
	posToCheck->set(this->getPosition()->toString());

	// Check bottop left (increase ranks)
	try {
		// Up to the end of the board
		int file = this->getPosition()->getFile();
		int rank = this->getPosition()->getRank();
		while ((--rank <= 8) && (--file <= 8)) {
			posToCheck->gotoBottomLeft();
			// If piece can move to square
			MoveCheckResult res = this->_checkMove(posToCheck, board);
			if (res == CAN_MOVE) {
				availableMoves.push_back(new Position(posToCheck));
			}
			else if (res == CAN_TAKE) {
				// If can take, we add this move to the available ones
				// but we can't move any further so we break the loop
				availableMoves.push_back(new Position(posToCheck));
				break;
			}
			else {
				// If can't move it means there's a friendly piece.
				// Break loop
				break;
			}
		}
	}
	catch (...) {}

	return availableMoves;
}
