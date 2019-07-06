#include "Square.h"

void Square::placePiece(Piece* piece) {
	this->piece = piece;
}

Piece* Square::getPiece() {
	return this->piece;
}
