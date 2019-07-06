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