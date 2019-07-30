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
#include <fstream>

#include "../Position/Position.h"
#include "../Move/Move.h"

#include "../TimeMachine/TimeMachine.h"

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
	this->inGame = false;
}

bool Game::New() {
	if (inGame) {
		this->reset();
		this->inGame = true;
	}
	else {
		// Create a new board
		this->board = new Board();

		// Create Time Machine
		this->tm = new TimeMachine(this, this->board);

		// Create chess pieces and attach them to their starting squares
		this->board->createPieces();

		this->playerTurn = 1;

		this->scorePlayer1 = 0;
		this->scorePlayer2 = 0;

		this->_printBoard();

		this->inGame = true;
	}
	return true;
}

bool Game::Load(string filename) {
	ifstream savefile(filename, ios::in | ios::binary);
	if (savefile.is_open()) {
		savefile.seekg(0, ios::end);
		size_t fileSize = savefile.tellg();
		savefile.seekg(0, ios::beg);

		// create a vector to hold all the bytes in the file
		std::vector<char> data(fileSize, 0);

		// read the file
		savefile.read(&data[0], fileSize);
		cout << "File is " << fileSize << " bytes long." << endl;
		for (int i = 0; i < data.size(); i+=4) {
			int file = data[i];
			int rank = data[i + 1];
			char letter = data[i + 2];
			bool isMoved = data[i + 3];

			cout << "Read a piece with: file=" << file << " rank=" << rank
				<< " letter=" << letter << " isMoved=" << (isMoved ? 1 : 0) << endl;
		}
		savefile.close();
	}
	else {
		return false;
	}
	return true;
}

bool Game::Save(string filename) {
	// We can only save if it's 1st player's turn
	if (this->playerTurn == 2) {
		return false;
	}
	// Open the file for writing
	ofstream savefile(filename);
	if (savefile.is_open()) {
		char SEP = CHAR_MAX;

		// Serialize pieces data

		// Get all pieces in a vector
		vector<Piece*> pieces = this->board->getPieces();
		// for every piece
		for (auto piece : pieces) {
			// Get the values we need to store
			char file = piece->getPosition()->getFile();
			char rank = piece->getPosition()->getRank();
			char letter = piece->pieceName()[0];
			if (piece->getColor() == BLACK) letter = tolower(letter);
			char isMoved = piece->hasMoved() ? 1 : 0;

			// Write the values to the file
			savefile.write((char*)& file, sizeof(char));
			savefile.write((char*)& rank, sizeof(char));
			savefile.write((char*)& letter, sizeof(char));
			savefile.write((char*)& isMoved, sizeof(char));
		}
		// Add separator
		savefile.write((char*)& SEP, sizeof(char));

		// Serialize TimeMachine stacks data

		// Get TM stack data
		vector<Move*> backMoves = this->tm->getBackStackMoves();
		vector<Move*> forwardMoves = this->tm->getForwardStackMoves();

		// Write TM back stack moves
		for (auto move : backMoves) {
			char originFile = move->getOrigin()->getFile();
			char originRank = move->getOrigin()->getRank();
			char destFile = move->getDestination()->getFile();
			char destRank = move->getDestination()->getRank();
			char player = move->getPlayer();

			savefile.write((char*)& originFile, sizeof(char));
			savefile.write((char*)& originRank, sizeof(char));
			savefile.write((char*)& destFile, sizeof(char));
			savefile.write((char*)& destRank, sizeof(char));
			savefile.write((char*)& player, sizeof(char));
		}

		// Add separator
		savefile.write((char*)& SEP, sizeof(char));

		// Write TM forward stack moves
		for (auto move : backMoves) {
			char originFile = move->getOrigin()->getFile();
			char originRank = move->getOrigin()->getRank();
			char destFile = move->getDestination()->getFile();
			char destRank = move->getDestination()->getRank();
			char player = move->getPlayer();

			savefile.write((char*)& originFile, sizeof(char));
			savefile.write((char*)& originRank, sizeof(char));
			savefile.write((char*)& destFile, sizeof(char));
			savefile.write((char*)& destRank, sizeof(char));
			savefile.write((char*)& player, sizeof(char));
		}

		// ^ BAD, not DRY, I'd rather put that on an internal method and call it twice.

		savefile.close();
	}
	else {
		return false;
	}
	return true;
}

void Game::reset() {
	// Create a new board
	this->board->reset();

	// Create chess pieces and attach them to their starting squares
	this->board->createPieces();

	this->playerTurn = 1;

	this->scorePlayer1 = 0;
	this->scorePlayer2 = 0;
}

bool Game::movePiece(int player, string origin, string destination, bool addToTimeMachine) {
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

			// Get available moves for origin piece
			vector<Position*> availableMoves = piece->getAvailableMoves(this->board);

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

				if (addToTimeMachine) {
					this->tm->addMove(move);
					this->_printBoard();
				}

				return true;
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

int Game::getPlayer() {
	return this->playerTurn;
}

bool Game::goBack() {
	bool res = this->tm->goBackwards();
	this->_printBoard();
	return res;
}

bool Game::goForward() {
	bool res = this->tm->goForwards();
	this->_printBoard();
	return res;
}
