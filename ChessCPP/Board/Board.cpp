#include "Board.h"

#include "../Pieces/Rook/Rook.h"
#include "../Pieces/Knight/Knight.h"
#include "../Pieces/Bishop/Bishop.h"
#include "../Pieces/Queen/Queen.h"
#include "../Pieces/King/King.h"
#include "../Pieces/Pawn/Pawn.h"

int Board::_letterToNumber(char letter) {
	return (int)letter - 'a' + 1;
}

pair<int, int> Board::_notationToFileAndRank(string notation) {
	int file = this->_letterToNumber(notation.at(0));
	int rank = notation.at(1) - '0';
	return pair<int, int>(file, rank);
}

void Board::_createPieces() {
	// White pieces
	this->getSquare("a1")->placePiece(new Rook(WHITE));
	this->getSquare("b1")->placePiece(new Knight(WHITE));
	this->getSquare("c1")->placePiece(new Bishop(WHITE));
	this->getSquare("d1")->placePiece(new Queen(WHITE));
	this->getSquare("e1")->placePiece(new King(WHITE));
	this->getSquare("f1")->placePiece(new Bishop(WHITE));
	this->getSquare("g1")->placePiece(new Knight(WHITE));
	this->getSquare("h1")->placePiece(new Rook(WHITE));

	string* files = new string[9]{ "", "a", "b", "c", "d", "e", "f", "g", "h" };

	for (int i = 1; i <= 8; i++) {
		cout << files[i] + "2" << endl;
		this->getSquare(files[i] + "2")->placePiece(new Pawn(WHITE));
	}

	// Black pieces
	this->getSquare("a8")->placePiece(new Rook(BLACK));
	this->getSquare("b8")->placePiece(new Knight(BLACK));
	this->getSquare("c8")->placePiece(new Bishop(BLACK));
	this->getSquare("d8")->placePiece(new King(BLACK));
	this->getSquare("e8")->placePiece(new Queen(BLACK));
	this->getSquare("f8")->placePiece(new Bishop(BLACK));
	this->getSquare("g8")->placePiece(new Knight(BLACK));
	this->getSquare("h8")->placePiece(new Rook(BLACK));

	for (int i = 1; i <= 8; i++) {
		this->getSquare(files[i] + "7")->placePiece(new Pawn(BLACK));
	}

}

Board::Board() {
	// Create squares
	this->squares = new Square * *[8];
	Color startWithColor = BLACK;
	for (int file = 0; file < 8; ++file) {
		this->squares[file] = new Square * [8];
	}
	for (int rank = 0; rank < 8; ++rank) {
		Color currentColor = startWithColor;
		for (int file = 0; file < 8; ++file) {
			this->squares[file][rank] = new Square(currentColor);
			currentColor = (Color)!currentColor;
		}
		startWithColor = (Color)!startWithColor;
	}

	// Create chess pieces and attach them to their squares
	this->_createPieces();
}

Square* Board::getSquare(string notation) {
	if (notation.length() == 2) {
		int file = this->_notationToFileAndRank(notation).first;
		int rank = this->_notationToFileAndRank(notation).second;

		// Check if the file and rank is correct
		if (((file > 0) && (file <= 8)) && ((rank > 0) && (rank <= 8))) {
			return squares[file - 1][rank - 1];
		}
	}
	return nullptr;
}