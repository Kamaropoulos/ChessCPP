/**
 * @file Knight.cpp
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief Knight piece logic.
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Knight.h"

Knight::Knight(Color color) : Piece(color) {
}

vector<Move*> Knight::getAvailableMoves(Board* board) {
	cout << "getAvalableMoves for " << this->pieceName() << endl;
	return vector<Move*>();
}
