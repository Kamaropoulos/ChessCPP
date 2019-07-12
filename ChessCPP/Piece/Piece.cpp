/**
 * @file Piece.cpp
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief Base class for the chess pieces.
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Piece.h"
#include "../Board/Board.h"

MoveCheckResult Piece::_checkMove(Position* posToCheck, Board* board) {
	MoveCheckResult result = CANT_MOVE;
	// If square is empty
	if (!board->getSquare(posToCheck)->hasPiece()) {
		result = CAN_MOVE;
	}

	// if there is a piece in that square
	if (board->getSquare(posToCheck)->hasPiece()) {
		// and if this piece is not the same color
		if (board->getSquare(posToCheck)->getColor() != this->getColor()) {
			result = CAN_TAKE;
		}
	}
	return result;
}

Piece::Piece(Position* pos, Color color) {
	this->position = pos;
	this->color = color;
	this->moved = false;
}

Position* Piece::getPosition() {
	return this->position;
}

Color Piece::getColor() {
	return this->color;
}

bool Piece::hasMoved() {
	return this->moved;
}
