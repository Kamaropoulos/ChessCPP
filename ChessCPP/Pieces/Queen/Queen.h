#pragma once
#include "../../Piece/Piece.h"
class Queen :
	public Piece {
public:
	Queen(Color color);
	string pieceName() { return "Queen"; }
};

