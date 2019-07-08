/**
 * @file Pawn.cpp
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief Pawn piece logic.
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Pawn.h"

Pawn::Pawn(Color color) : Piece(color) {
}

vector<Move*> Pawn::getAvailableMoves(Board* board) {
	cout << "getAvalableMoves for " << this->pieceName() << endl;
	return vector<Move*>();
}
