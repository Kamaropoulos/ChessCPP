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

Knight::Knight(Position* pos, Color color) : Piece(pos, color) {
}

vector<Move*> Knight::getAvailableMoves(Board* board) {
	cout << "getAvalableMoves for " << this->pieceName() << endl;
	return vector<Move*>();
}
