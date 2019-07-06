/**
 * @file Knight.h
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief Knight piece logic.
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once
#include "../../Piece/Piece.h"
class Knight :
	public Piece {
public:
	Knight(Color color);
	string pieceName() { return "Knight"; }
};

