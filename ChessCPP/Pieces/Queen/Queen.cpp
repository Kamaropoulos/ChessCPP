/**
 * @file Queen.cpp
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief Queen piece logic.
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Queen.h"

Queen::Queen(Position* pos, Color color) : Piece(pos, color, 9) {
}

vector<Position*> Queen::getAvailableMoves(Board* board) {
	cout << "getAvalableMoves for " << this->pieceName() << endl;
	return vector<Position*>();
}
