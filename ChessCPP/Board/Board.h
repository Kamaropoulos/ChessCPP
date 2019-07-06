/**
 * @file Board.h
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief Header file for the chess board, holding information for the squares and the pieces on them.
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

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
