#include "Position.h"

int Position::_letterToNumber(char letter) {
	// Add 1 to start from 1 instead of 0
	return (int)letter - 'a' + 1;
}

char Position::_numberToLetter(int number) {
	return (char)number + 'a' - 1;
}

// TODO: Maybe replace with operator= overload for file and rank to trigger this automagically
void Position::_updateString() {
	this->str = this->_numberToLetter(this->file) + to_string(this->rank);
}

pair<int, int> Position::stringToFileAndRank(string notation) {
	// Convert the first character to a number
	int file = Position::_letterToNumber(notation.at(0));
	// Get int from character
	int rank = notation.at(1) - '0';

	// Return pair of integers
	// first is file, second is rank
	return pair<int, int>(file, rank);
}

string Position::toString() {
	return this->str;
}

Position::Position(string posStr) {
	if (posStr.length() == 2) {
		int file = this->stringToFileAndRank(posStr).first;
		int rank = this->stringToFileAndRank(posStr).second;

		if (((file > 0) && (file <= 8)) && ((rank > 0) && (rank <= 8))) {
			this->file = file;
			this->rank = rank;
			this->_updateString();

			return;
		}
	}
	throw exception("Invalid position string!");
}

Position::Position(int file, int rank) {
	if (((file > 0) && (file <= 8)) && ((rank > 0) && (rank <= 8))) {
		this->file = file;
		this->rank = rank;
		this->_updateString();

		return;
	}
	throw exception("Invalid position!");
}

void Position::set(string posStr) {
	if (posStr.length() == 2) {
		int file = this->stringToFileAndRank(posStr).first;
		int rank = this->stringToFileAndRank(posStr).second;

		if (((file > 0) && (file <= 8)) && ((rank > 0) && (rank <= 8))) {
			this->file = file;
			this->rank = rank;
			this->_updateString();

			return;
		}
	}
	throw exception("Invalid position string!");
}

void Position::set(int file, int rank) {
	if (((file > 0) && (file <= 8)) && ((rank > 0) && (rank <= 8))) {
		this->file = file;
		this->rank = rank;
		this->_updateString();

		return;
	}
	throw exception("Invalid position!");
}

void Position::setFile(int file) {
	if ((file > 0) && (file <= 8)) {
		this->file = file;
		this->_updateString();

		return;
	}
	throw exception("Invalid position!");
}

void Position::setFile(char file) {
	int newFile = this->_letterToNumber(file);
	if ((newFile > 0) && (newFile <= 8)) {
		this->file = newFile;
		this->_updateString();

		return;
	}
	throw exception("Invalid position!");
}

void Position::setRank(int rank) {
	if ((rank > 0) && (rank <= 8)) {
		this->rank = rank;
		this->_updateString();

		return;
	}
	throw exception("Invalid position!");
}

int Position::getFile() {
	return this->file;
}

int Position::getRank() {
	return this->rank;
}

void Position::gotoLeft() {
	this->setFile(this->file - 1);
}

void Position::gotoRight() {
	this->setFile(this->file + 1);
}

void Position::gotoTop() {
	this->setRank(this->rank + 1);
}

void Position::gotoBottom() {
	this->setFile(this->file - 1);
}

void Position::gotoTopLeft() {
	this->setFile(this->file - 1);
	this->setRank(this->rank + 1);
}

void Position::gotoTopRight() {
	this->setFile(this->file + 1);
	this->setRank(this->rank + 1);
}

void Position::gotoBottomLeft() {
	this->setFile(this->file - 1);
	this->setRank(this->rank - 1);
}

void Position::gotoBottomRight() {
	this->setFile(this->file - 1);
	this->setRank(this->rank + 1);
}
