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

#include <string>
#include <iostream>
#include <vector>
#include "../Move/Move.h"

using namespace std;

enum Color { WHITE, BLACK };

class Piece {
public:
	Color color;
	Piece(Color color);
	virtual string pieceName() = 0;
	virtual vector<Move*> getAvailableMoves();
};
