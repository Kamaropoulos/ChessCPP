#pragma once

#include <string>

using namespace std;

enum Color { WHITE, BLACK };

class Piece {
public:
	Color color;
	Piece(Color color);
	virtual string pieceName() = 0;
};

