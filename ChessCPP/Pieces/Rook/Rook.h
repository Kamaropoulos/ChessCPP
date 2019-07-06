#pragma once
#include "../../Piece/Piece.h"
class Rook :
	public Piece {
public:
	Rook(Color color);
	string pieceName() { return "Rook"; }
};

