/**
 * @file Pawn.h
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief Pawn piece logic.
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once
#include "../../Piece/Piece.h"
#include "../../Board/Board.h"
class Pawn :
	public Piece {
public:
	Pawn(Position* pos, Color color);
	string pieceName() { return "Pawn"; }
	vector<Position*> getAvailableMoves(Board* board);
};

