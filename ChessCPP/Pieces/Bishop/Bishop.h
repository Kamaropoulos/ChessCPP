#pragma once
#include "../../Piece/Piece.h"
class Bishop :
	public Piece {
public:
	Bishop(Color color);
	string pieceName() { return "Bishop"; }
};

