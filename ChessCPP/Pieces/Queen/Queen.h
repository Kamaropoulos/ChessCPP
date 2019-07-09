/**
 * @file Queen.h
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief Queen piece logic.
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once
#include "../../Piece/Piece.h"
class Queen :
	public Piece {
public:
	Queen(Position* pos, Color color);
	string pieceName() { return "Queen"; }
	vector<Move*> getAvailableMoves(Board* board);
};

