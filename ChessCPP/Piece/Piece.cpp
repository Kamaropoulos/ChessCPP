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

Piece::Piece(string position, Color color) {
	this->position = position;
	this->color = color;
	this->moved = false;
}

string Piece::getPosition() {
	return this->position;
}

bool Piece::hasMoved() {
	return this->moved;
}
