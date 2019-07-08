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

Rook::Rook(Color color) : Piece(color) {
}

vector<Move*> Rook::getAvailableMoves(Board* board) {
	cout << "getAvalableMoves for " << this->pieceName() << endl;
	return vector<Move*>();
}
