/**
 * @file Queen.cpp
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief Queen piece logic.
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Queen.h"

Queen::Queen(Position* pos, Color color) : Piece(pos, color, 9) {
}

vector<Position*> Queen::getAvailableMoves(Board* board) {
	vector<Position*> availableMoves;
	// The Queen can make the same moves like the Rook and the Bishop combined
	
	Position* posToCheck = new Position(this->position);

	// Check forward (increase ranks)
	try {
		// Up to the end of the board
		int rank = this->getPosition()->getRank();
		while (++rank <= 8) {
			posToCheck->gotoTop();
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

	// Check backwards (decrease ranks)
	try {
		// Up to the end of the board
		int rank = this->getPosition()->getRank();
		while (--rank >= 1) {
			posToCheck->gotoBottom();
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

	// Check left (decrease files)
	try {
		// Up to the end of the board
		int file = this->getPosition()->getFile();
		while (--file >= 1) {
			posToCheck->gotoLeft();
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

	// Check left (decrease files)
	try {
		// Up to the end of the board
		int file = this->getPosition()->getFile();
		while (--file >= 1) {
			posToCheck->gotoLeft();
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

	// Check right (increase files)
	try {
		// Up to the end of the board
		int file = this->getPosition()->getFile();
		while (++file <= 8) {
			posToCheck->gotoRight();
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
