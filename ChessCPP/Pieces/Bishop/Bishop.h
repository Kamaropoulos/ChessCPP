/**
 * @file Bishop.h
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief Bishop piece logic.
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once
#include "../../Piece/Piece.h"
class Bishop :
	public Piece {
public:
	Bishop(Position* pos, Color color);
	string pieceName() { return "Bishop"; }
	vector<Position*> getAvailableMoves(Board* board);
};

