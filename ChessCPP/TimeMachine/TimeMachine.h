#pragma once
#include <stack>
#include "../Board/Board.h"
#include "../Move/Move.h"
class TimeMachine {
private:
	stack<Move*> back;
	stack<Move*> forward;
	bool isTimeTravelling = false;

public:
	bool goBackwards();
	bool goForwards();
	bool resume();
	void addMove(Move* move);
};

