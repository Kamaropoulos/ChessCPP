/**
 * @file King.cpp
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief King piece logic
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "King.h"

King::King(Position* pos, Color color) : Piece(pos, color, 0) {
}

vector<Position*> King::getAvailableMoves(Board* board) {
	cout << "getAvalableMoves for " << this->pieceName() << endl;
	return vector<Position*>();
}
