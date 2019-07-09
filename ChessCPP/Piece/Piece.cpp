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
