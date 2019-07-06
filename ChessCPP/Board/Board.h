#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "../Square/Square.h"

using namespace std;

class Board {
private:
	Square*** squares = nullptr;
	int _letterToNumber(char letter);
	pair<int, int> _notationToFileAndRank(string notation);
	void _createPieces();

public:
	Board();
	Square* getSquare(string notation);
};

