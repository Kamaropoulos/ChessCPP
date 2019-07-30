#pragma once
#include "../Game/Game.h"
#include "../MovesStack/MovesStack.h"
class TimeMachine {
private:
	MovesStack back;
	MovesStack forward;
	bool isTimeTravelling = false;
	Game* game = nullptr;
	Board* board = nullptr;

public:
	TimeMachine(Game* game, Board* board);
	bool goBackwards();
	bool goForwards();
	bool resume();
	void addMove(Move* move);
	vector<Move*> getBackStackMoves();
	vector<Move*> getForwardStackMoves();
};

