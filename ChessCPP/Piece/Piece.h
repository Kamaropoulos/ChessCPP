/**
 * @file Piece.h
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief Base class for the chess pieces.
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "../Move/Move.h"
class Board; // Forward declare Board

#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "../Position/Position.h"

using namespace std;

enum Color { WHITE, BLACK };

class Piece {
protected:
	bool moved;
	 Position* position;
	Color color;
public:
	Piece(Position* pos, Color color);
	Position* getPosition();
	Color getColor();
	bool hasMoved();
	virtual string pieceName() = 0;
	virtual vector<Move*> getAvailableMoves(Board* board) = 0;
};
