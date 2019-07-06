/**
 * @file Game.h
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief High-level game overview and management.
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once
#include <string>
#include "../Board/Board.h"

using namespace std;

class Game {
private:
	Board* board;

public:
	Game();
};
