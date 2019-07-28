/**
 * @file Board.cpp
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief The chess board, holding information for the squares and the pieces on them.
 * @version 0.1
 * @date 2019-07-06
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Board.h"

#include "../Pieces/Rook/Rook.h"
#include "../Pieces/Knight/Knight.h"
#include "../Pieces/Bishop/Bishop.h"
#include "../Pieces/Queen/Queen.h"
#include "../Pieces/King/King.h"
#include "../Pieces/Pawn/Pawn.h"

int Board::_letterToNumber(char letter) {
	// Add 1 to start from 1 instead of 0
	return (int)letter - 'a' + 1;
}

pair<int, int> Board::_notationToFileAndRank(string notation) {
	// Convert the first character to a number
	int file = this->_letterToNumber(notation.at(0));
	// Get int from character
	int rank = notation.at(1) - '0';

	// Return pair of integers
	// first is file, second is rank
	return pair<int, int>(file, rank);
}

void Board::createPieces() {
	// Array to hold file characters
	// First one was left empty to use base-1 instead of base-0 for the first element
	string* files = new string[9]{ "", "a", "b", "c", "d", "e", "f", "g", "h" };

	// Create and attach white back pieces
	this->getSquare("a1")->placePiece(new Rook(new Position("a1"), WHITE));
	this->getSquare("b1")->placePiece(new Knight(new Position("b1"), WHITE));
	this->getSquare("c1")->placePiece(new Bishop(new Position("c1"), WHITE));
	this->getSquare("d1")->placePiece(new Queen(new Position("d1"), WHITE));
	this->getSquare("e1")->placePiece(new King(new Position("e1"), WHITE));
	this->getSquare("f1")->placePiece(new Bishop(new Position("f1"), WHITE));
	this->getSquare("g1")->placePiece(new Knight(new Position("g1"), WHITE));
	this->getSquare("h1")->placePiece(new Rook(new Position("h1"), WHITE));

	// Create and attach white pawns
	for (int i = 1; i <= 8; i++) {
		this->getSquare(files[i] + "2")->placePiece(new Pawn(new Position(files[i] + "2"), WHITE));
	}

	// Create and attach black back pieces
	this->getSquare("a8")->placePiece(new Rook(new Position("a8"), BLACK));
	this->getSquare("b8")->placePiece(new Knight(new Position("b8"), BLACK));
	this->getSquare("c8")->placePiece(new Bishop(new Position("c8"), BLACK));
	this->getSquare("d8")->placePiece(new King(new Position("d8"), BLACK));
	this->getSquare("e8")->placePiece(new Queen(new Position("e8"), BLACK));
	this->getSquare("f8")->placePiece(new Bishop(new Position("f8"), BLACK));
	this->getSquare("g8")->placePiece(new Knight(new Position("g8"), BLACK));
	this->getSquare("h8")->placePiece(new Rook(new Position("h8"), BLACK));

	// Create and attach black pawns
	for (int i = 1; i <= 8; i++) {
		this->getSquare(files[i] + "7")->placePiece(new Pawn(new Position(files[i] + "7"), BLACK));
	}

}

Board::Board() {
	// Initialize 2d array to hold Squares
	this->squares = new Square * *[8];

	// Initialize the second level arrays of the 2d array
	for (int file = 0; file < 8; ++file) {
		this->squares[file] = new Square * [8];
	}

	// We are going to start with the bottom left square (a1)
	// Then we'll move files to the left and once we reach the end of the line
	// we'll move to the above rank, starting again from the first file.

	// The color of the first square is black
	Color startWithColor = BLACK;

	// Each line's first square's color is the oposite of the previous one.
	// So we'll be switching color every time we reach the end of the line.

	// For each rank in the board:
	for (int rank = 0; rank < 8; ++rank) {
		// Set the color for the current square the starting
		// color since we are at the beginning of the line.
		Color currentColor = startWithColor;

		// For each file of the current rank:
		for (int file = 0; file < 8; ++file) {
			// Create a new Square using the current color and store it on the 
			// correct position of the squares array based on it's file and rank.
			this->squares[file][rank] = new Square(currentColor);

			// Switch the current color
			currentColor = (Color)!currentColor;
		}

		// We reached the end of the line.
		// The next line will have to oposite starting color so we have to switch it.
		startWithColor = (Color)!startWithColor;
	}
}

Square* Board::getSquare(string notation) {
	// Square notation should only have 2 characters
	if (notation.length() == 2) {
		// Extract the file and the rank of the requested square
		// using the _notationToFileAndRank function.
		int file = this->_notationToFileAndRank(notation).first;
		int rank = this->_notationToFileAndRank(notation).second;

		// Check if the file and rank is within the valid limits
		if (((file > 0) && (file <= 8)) && ((rank > 0) && (rank <= 8))) {
			// Return the requested square.
			// We substract 1 since the array is base-0
			// but the file and rank are base-1.
			return squares[file - 1][rank - 1];
		}
	}

	// If the passed string was invalid, return nullptr.
	return nullptr;
}

Square* Board::getSquare(Position* pos) {
	return this->getSquare(pos->toString());
}
