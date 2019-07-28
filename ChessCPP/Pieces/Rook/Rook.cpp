/**
 * @file Rook.cpp
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief Rook piece logic.
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Rook.h"

Rook::Rook(Position* pos, Color color) : Piece(pos, color, 5) {
}

vector<Position*> Rook::getAvailableMoves(Board* board) {
	cout << "getAvalableMoves for " << this->pieceName() << " at " << this->getPosition()->toString() << endl;
	return vector<Position*>();
}
