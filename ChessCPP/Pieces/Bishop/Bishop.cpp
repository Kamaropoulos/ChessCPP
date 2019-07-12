/**
 * @file Bishop.cpp
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief Bishop piece logic.
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Bishop.h"

Bishop::Bishop(Position* pos, Color color) : Piece(pos, color) {
}

vector<Position*> Bishop::getAvailableMoves(Board* board) {
	cout << "getAvalableMoves for " << this->pieceName() << endl;
	return vector<Position*>();
}
