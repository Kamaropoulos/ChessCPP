/**
 * @file King.h
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief King piece logic.
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once
#include "../../Piece/Piece.h"
class King :
	public Piece {
public:
	King(Position* pos, Color color);
	string pieceName() { return "King"; }
	vector<Position*> getAvailableMoves(Board* board);
};

