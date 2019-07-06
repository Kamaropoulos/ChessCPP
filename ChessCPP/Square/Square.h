#pragma once
#include "../Piece/Piece.h"
class Square {
private:
	Piece* piece = nullptr;
public:
	Color color;
	Square(Color color);
	void placePiece(Piece* piece);
	bool hasPiece();
	Piece* getPiece();
};

