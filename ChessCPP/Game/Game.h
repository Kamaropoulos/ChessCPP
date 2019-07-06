

#pragma once
#include <string>
#include "../Board/Board.h"

using namespace std;

class Game {
private:
	Board* board;
	int _createPieces();

public:
	Game();
};

