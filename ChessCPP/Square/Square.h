/**
 * @file Square.h
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief Chess board square.
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once
#include "../Piece/Piece.h"
class Square {
private:
	Piece* piece = nullptr;
public:
	Color color;
	Square(Color color);
	void placePiece(Piece* piece);
	bool hasPiece();
	Piece* getPiece();
	Color getColor();
};
