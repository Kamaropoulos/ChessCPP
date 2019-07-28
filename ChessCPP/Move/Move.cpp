/**
 * @file Move.cpp
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief Piece movement descriptor
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Move.h"

Move::Move(int player, Position* origin, Position* destination) {
	this->origin = origin;
	this->destination = destination;
	this->player = player;
}

Position* Move::getOrigin() {
	return this->origin;
}

Position* Move::getDestination() {
	return this->destination;
}

void Move::setResult(MoveResult result) {
	this->result = result;
}

void Move::setTakenPiece(Piece* takenPiece) {
	this->takenPiece = takenPiece;
}

MoveResult Move::getResult() {
	return this->result;
}

Piece* Move::getTakenPiece() {
	return this->takenPiece;
}
