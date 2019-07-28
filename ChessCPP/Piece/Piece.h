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

#pragma once

#include "../Move/Move.h"
class Board; // Forward declare Board

#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "../Position/Position.h"

using namespace std;

enum Color { WHITE, BLACK };
enum MoveResult { CANT_MOVE, CAN_MOVE, CAN_TAKE };

class Piece {
protected:
	bool moved;
	Position* position;
	Color color;
	int value;
	MoveResult _checkMove(Position* posToCheck, Board* board);
public:
	Piece(Position* pos, Color color, int value);
	Position* getPosition();
	void setPosition(Position* pos);
	Color getColor();
	bool hasMoved();
	void setMoved();
	int getValue();
	virtual string pieceName() = 0;
	virtual vector<Position*> getAvailableMoves(Board* board) = 0;
};
