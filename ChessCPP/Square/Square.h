#pragma once
#include "../Piece/Piece.h"
class Square {
public:
	Piece* piece = nullptr;
	void placePiece(Piece* piece);
	Piece* getPiece();
};

