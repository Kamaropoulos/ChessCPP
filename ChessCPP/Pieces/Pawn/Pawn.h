#pragma once
#include "../../Piece/Piece.h"
class Pawn :
	public Piece {
public:
	Pawn(Color color);
	string pieceName() { return "Pawn"; }
};

