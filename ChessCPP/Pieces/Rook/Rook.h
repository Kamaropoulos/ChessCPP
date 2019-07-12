/**
 * @file Rook.h
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief Rook piece logic.
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once
#include "../../Piece/Piece.h"
class Rook :
	public Piece {
public:
	Rook(Position* pos, Color color);
	string pieceName() { return "Rook"; }
	vector<Position*> getAvailableMoves(Board* board);
};

