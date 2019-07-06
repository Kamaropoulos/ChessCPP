/**
 * @file Square.cpp
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief Chess board square.
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Square.h"

Square::Square(Color color) {
	this->color = color;
}

void Square::placePiece(Piece* piece) {
	this->piece = piece;
}

bool Square::hasPiece() {
	if (this->piece != nullptr) return true;
	return false;
}

Piece* Square::getPiece() {
	return this->piece;
}