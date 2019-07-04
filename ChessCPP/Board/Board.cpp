#include "Board.h"

int Board::_letterToNumber(char letter) {
	return (int)letter - 'a' + 1;
}

pair<int, int> Board::_notationToFileAndRank(string notation) {
	int file = this->_letterToNumber(notation.at(0));
	int rank = notation.at(1) - '0';
	return pair<int, int>(file, rank);
}

Board::Board() {
	this->squares = new Square * *[8];
	for (int file = 0; file < 8; ++file) {
		this->squares[file] = new Square * [8];

		for (int rank = 0; rank < 8; ++rank) {
			this->squares[file][rank] = new Square();
		}
	}
}

Square* Board::getSquare(string notation) {
	if (notation.length == 2) {
		int file = this->_notationToFileAndRank(notation).first;
		int rank = this->_notationToFileAndRank(notation).second;
		if (((file > 0) && (file <= 8)) && ((rank > 0) && (rank <= 8))) {
			return squares[file - 1][rank - 1];
		}
	}
	return nullptr;
}
