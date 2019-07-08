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
class Pawn :
	public Piece {
public:
	Pawn(Color color);
	string pieceName() { return "Pawn"; }
	vector<Move*> getAvailableMoves() override;
};

