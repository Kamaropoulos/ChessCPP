#pragma once
#include "../../Piece/Piece.h"
class Knight :
	public Piece {
public:
	Knight(Color color);
	string pieceName() { return "Knight"; }
};

