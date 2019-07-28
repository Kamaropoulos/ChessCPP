/**
 * @file Move.h
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief Piece movement descriptor
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#include "../Position/Position.h"

class Move {
private:
	Position* origin;
	Position* destination;
	int player;

public:
	Move(int player, Position* origin, Position* destination);
	Position* getOrigin();
	Position* getDestination();
};

