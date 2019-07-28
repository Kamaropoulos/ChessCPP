/**
 * @file Game.cpp
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief High-level game overview and management.
 * @version 0.1
 * @date 2019-07-06
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Game.h"

#include <algorithm>

#include "../Position/Position.h"

void Game::_printStatus() {
	string* files = new string[9]{ "", "a", "b", "c", "d", "e", "f", "g", "h" };
	for (int rank = 1; rank <= 8; ++rank) {
		for (int file = 1; file <= 8; ++file) {
			Square* sq = this->board->getSquare(files[file] + to_string(rank));
			if (sq != nullptr) {
				if (this->board->getSquare(files[file] + to_string(rank))->hasPiece()) {
					cout << "Square " << files[file] << to_string(rank) << " is " << ((this->board->getSquare(files[file] + to_string(rank))->getColor() == BLACK) ? "black" : "white") << " and holds a " << ((this->board->getSquare(files[file] + to_string(rank))->getPiece()->getColor() == BLACK) ? "black " : "white ") << this->board->getSquare(files[file] + to_string(rank))->getPiece()->pieceName() << endl;
				}
				else {
					cout << "Square " << files[file] << to_string(rank) << " is " << ((this->board->getSquare(files[file] + to_string(rank))->getColor() == BLACK) ? "black" : "white") << " and it's empty" << endl;
				}
			}
			else {
				cout << "Square " << files[file] << to_string(rank) << " is null" << endl;
			}
		}
	}
}

void Game::_printBoard() {
	cout << "    a b c d e f g h " << endl;
	cout << "   ________________" << endl;
	for (int rank = 8; rank >= 1; rank--) {
		cout << rank << " | ";
		for (int file = 1; file <= 8; file++) {
			Position* currentPos = new Position(file, rank);
			Square* square = this->board->getSquare(currentPos->toString());
			if (square->hasPiece()) {
				Piece* piece = square->getPiece();
				char representation = piece->pieceName()[0];
				if (piece->getColor() == BLACK) representation = tolower(representation);
				cout << representation << " ";
				//cout << piece->getPosition()->toString() << " ";
			}
			else {
				cout << "- ";
			}
		}
		cout << "| " << rank << endl;
	}
	cout << "   ________________" << endl;
	cout << "    a b c d e f g h" << endl;
}

/**
  * @brief Construct a new Game:: Game object
  *
  * It creates a new board and the pieces for the two players.
  */
Game::Game() {
	// Create a new board
	this->board = new Board();

	// Create chess pieces and attach them to their starting squares
	this->board->createPieces();

	this->playerTurn = 1;

	this->scorePlayer1 = 0;
	this->scorePlayer2 = 0;

	vector<Position*> moves = this->board->getSquare("b2")->getPiece()->getAvailableMoves(this->board);

	this->_printBoard();
}

bool Game::movePiece(int player, string origin, string destination) {
	// If it's not this player's turn, return false
	if (this->playerTurn != player) return false;

	// Create movement object
	Move* move = new Move(player, new Position(origin), new Position(destination));

	// If there's a piece on the origin square
	if (this->board->getSquare(origin)->hasPiece()) {
		// and the piece belongs to the current player
		if (this->board->getSquare(origin)->getPiece()->getColor() == ((player == 1) ? WHITE : BLACK)) {
			// Get piece for easy access
			Piece* piece = this->board->getSquare(origin)->getPiece();

			vector<Position*> availableMoves = piece->getAvailableMoves(this->board);
			for (int i = 0; i < availableMoves.size(); i++) {
				cout << availableMoves[i]->toString() << endl;
			}

			// If attempted move exists in the available moves
			auto it = find_if(availableMoves.begin(), availableMoves.end(), [&move](Position* obj) {return obj->toString() == move->getDestination()->toString(); });

			if (it != availableMoves.end()) {
				// Action is available, move the piece
				// If there's an enemy piece at the destination square
				if (this->board->getSquare(destination)->hasPiece()) {
					// Remove piece and give the points to the player that captured the piece
					if (player == 1) {
						this->scorePlayer1 += this->board->getSquare(destination)->getPiece()->getValue();
					}
					else {
						this->scorePlayer2 += this->board->getSquare(destination)->getPiece()->getValue();
					}
					// Remove enemy piece
					this->board->getSquare(destination)->emptySquare();
				}
				// Move piece to its destination
				this->board->getSquare(destination)->placePiece(this->board->getSquare(origin)->getPiece());
				this->board->getSquare(origin)->emptySquare();
				this->board->getSquare(destination)->getPiece()->setPosition(new Position(destination));
				this->board->getSquare(destination)->getPiece()->setMoved();

				this->playerTurn = (playerTurn == 1) ? 2 : 1;

				this->_printBoard();
			}
		}
	}
	return false;
}

pair<int, int> Game::getScore() {
	return pair<int, int>(scorePlayer1, scorePlayer2);
}

vector<Position*> Game::getAvailableMoves(Position* pos) {

	// If square is empty, return empty vector
	if (!this->board->getSquare(pos)->hasPiece()) {
		return vector<Position*>();
	}
	return this->board->getSquare(pos)->getPiece()->getAvailableMoves(this->board);
}
