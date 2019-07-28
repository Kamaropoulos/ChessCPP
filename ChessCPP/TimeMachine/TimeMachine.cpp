#include "TimeMachine.h"

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
			this->back.push(this->forward.top());
			this->forward.pop();
		}
	}
}

void TimeMachine::addMove(Move* move) {
	if (isTimeTravelling) {
		// Since we are time travelling, adding a move will
		// effectivelly start a new traversal tree, thus, resetting
		// the previous "future" moves. That's why we have to clear
		// the forwards stack.
		this->forward = stack<Move*>();
	}
	this->back.push(move);
}
