#include "TimeMachine.h"

TimeMachine::TimeMachine(Game* game, Board* board) {
	this->game = game;
	this->board = board;
}

bool TimeMachine::goBackwards() {
	// Set is travelling
	this->isTimeTravelling = true;

	// Reset board
	this->game->reset();
	this->board->createPieces();

	// Pop last move from back stack into forward stack
	this->forward.push(this->back.top());
	this->back.pop();

	// Replay all moves from back
	for (auto move : this->back._Get_container()) {
		this->game->movePiece(move->getPlayer(), move->getOrigin()->toString(), move->getDestination()->toString(), false);
	}
	return true;
}

bool TimeMachine::goForwards() {
	if (this->isTimeTravelling) {
		// Apply top of forward stack and pop it into the back stack
		auto move = this->forward.top();
		this->game->movePiece(move->getPlayer(), move->getOrigin()->toString(), move->getDestination()->toString(), false);
		
		// Push move into back stack
		this->back.push(move);
		this->forward.pop();

		// Update isTimeTravelling flag if forward stack is empty
		if (this->forward.empty())
			this->isTimeTravelling = false;

		return true;
	}
	return false;
}

bool TimeMachine::resume() {
	if (!this->isTimeTravelling && this->forward.empty()) {
		return true;
	}

	if (this->forward.empty()) {
		this->isTimeTravelling = false;
		return true;
	}

	if (!this->forward.empty()) {
		while (!this->forward.empty()) {
			this->goForwards();
		}
		return true;
	}
	return false;
}

void TimeMachine::addMove(Move* move) {
	if (isTimeTravelling) {
		// Since we are time travelling, adding a move will
		// effectivelly start a new traversal tree, thus, resetting
		// the previous "future" moves. That's why we have to clear
		// the forwards stack.
		this->forward = MovesStack();
	}
	this->back.push(move);
}
