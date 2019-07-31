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

/**
 * @brief Chess board class
 *
 */
class Board {
private:
	Square*** squares = nullptr;

	/**
	 * @brief Converts a lower-case letter to a number
	 *
	 * @param letter A char with the letter to convert
	 * @return int The number for the passed letter
	 */
	int _letterToNumber(char letter);

	/**
	 * @brief Extracts the numeric values for the square file and rank from a string
	 *
	 * @param notation A string with a square's file and rank in algebraic notation
	 * @return pair<int, int> A pair of integers holding the numeric values of the
	 * 						  file and rank of the square
	 */
	pair<int, int> _notationToFileAndRank(string notation);

public:

	/**
	 * @brief Construct a new Board object
	 *
	 */
	Board();

	/**
	 * @brief Creates and attaches the chess pieces for both players to the board
	 *
	 */
	void createPieces();

	/**
	 * @brief Get a Square by it's file and rank
	 *
	 * @param notation A string holding the square's file and rank
	 * @return Square* The Square for the passed file and rank
	 */
	Square* getSquare(string notation);

	Square* getSquare(Position* pos);

	vector<Piece*> getPieces();

	void reset();

	void attachPiece(Piece* piece);
};
