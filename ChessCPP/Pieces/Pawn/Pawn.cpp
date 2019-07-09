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

Pawn::Pawn(Position* pos, Color color) : Piece(pos, color) {
}

vector<Move*> Pawn::getAvailableMoves(Board* board) {
	// Movement direction: Increase rank if white, decrease rank if black.

	// Possible moves:
	// - If first move, 1 forward and 2 forward if empty
	// - Diagonically to the left and right if enemy piece

	if (!this->hasMoved()) {
		
	}
	return vector<Move*>();
}
