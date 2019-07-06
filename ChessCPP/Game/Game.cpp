#include "Game.h"

int Game::_createPieces() {
	return 0;
}

Game::Game() {
	this->board = new Board();
	this->_createPieces();
	this->board->getSquare("c4");
}
