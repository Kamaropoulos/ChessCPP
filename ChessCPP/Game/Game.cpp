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

#include "../Pieces/Pawn/Pawn.h"
#include "../Pieces/Knight/Knight.h"
#include "../Pieces/Bishop/Bishop.h"
#include "../Pieces/Rook/Rook.h"
#include "../Pieces/King/King.h"
#include "../Pieces/Queen/Queen.h"

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
				if (piece->pieceName() == "Knight") representation = 'N';
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
		// Reset game
		this->reset();
		// Create chess pieces and attach them to their starting squares
		this->board->createPieces();
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

		this->inGame = true;
	}
	return true;
}

bool Game::Load(string filename) {
	if (inGame) {
		// Reset game
		this->reset();
		this->inGame = true;
	}
	else {
		// Create a new board
		this->board = new Board();

		// Create Time Machine
		this->tm = new TimeMachine(this, this->board);
	}

	ifstream savefile(filename, ios::in | ios::binary);
	if (savefile.is_open()) {
		char SEP = CHAR_MAX;

		savefile.seekg(0, ios::end);
		size_t fileSize = savefile.tellg();
		savefile.seekg(0, ios::beg);

		// create a vector to hold all the bytes in the file
		std::vector<char> data(fileSize, 0);

		std::vector<char> piecesData;
		int searchCursor = 0;

		// Get all bytes into the vector
		savefile.read(&data[0], fileSize);
		//cout << "File is " << fileSize << " bytes long." << endl;

		// Separate piece data
		for (int i = searchCursor; i < data.size(); i++) {
			// We want to find the point where the piece data end
			// and the TimeMachine data start. The transition point
			// at the first CHAR_MAX (SEP) byte. That's where we'll
			// set the search cursor in order to continue from that
			// part for constructing the Time Machine data again.
			if (data[i] != SEP) {
				piecesData.push_back(data[i]);
			}
			else {
				// Increase i to "consume" separator character
				searchCursor = ++i;
				break;
			}
		}

		//cout << "piecesData.size()=" << piecesData.size() << endl;
		// Parse the piece data
		for (int i = 0; i < piecesData.size(); i+=4) {
			int file = piecesData[i];
			int rank = piecesData[i + 1];
			char letter = piecesData[i + 2];
			bool isMoved = piecesData[i + 3];

			// Create piece
			Piece* piece;
			// Select piece type
			switch (tolower(letter)) {
				case 'p':
					piece = new Pawn(new Position(file, rank), isupper(letter) ? WHITE : BLACK);
					break;
				case 'n':
					piece = new Knight(new Position(file, rank), isupper(letter) ? WHITE : BLACK);
					break;
				case 'b':
					piece = new Bishop(new Position(file, rank), isupper(letter) ? WHITE : BLACK);
					break;
				case 'k':
					piece = new King(new Position(file, rank), isupper(letter) ? WHITE : BLACK);
					break;
				case 'q':
					piece = new Queen(new Position(file, rank), isupper(letter) ? WHITE : BLACK);
					break;
				case 'r':
					piece = new Rook(new Position(file, rank), isupper(letter) ? WHITE : BLACK);
					break;
				default:
					throw;
			}

			// Attach piece to board
			this->board->attachPiece(piece);
			/*
			cout << "Read a piece with: file=" << file << " rank=" << rank
				<< " letter=" << letter << " isMoved=" << (isMoved ? 1 : 0) << endl;*/
		}

		// Separate TM stack data
		vector<char> backData;
		for (int i = searchCursor; i < data.size(); i++) {
			// We want to find the point where the back stack data end
			// and the forward stack data start. The transition point
			// at the first CHAR_MAX (SEP) byte. That's where we'll
			// set the search cursor in order to continue from that
			// part for constructing the forward stack data again.
			if (data[i] != SEP) {
				backData.push_back(data[i]);
			}
			else {
				// Increase i to "consume" separator character
				searchCursor = ++i;
				break;
			}
		}

		// Parse the TM back stack data
		for (int i = 0; i < backData.size(); i += 5) {
			int originFile = backData[i];
			int originRank = backData[i + 1];
			int destFile = backData[i + 2];
			int destRank = backData[i + 3];
			int player = backData[i + 4];

			// Create move to push
			Move* move = new Move(player, new Position(originFile, originRank), new Position(destFile, destRank));

			this->tm->pushMoveBack(move);

			//cout << "Read a back stack elem: orF=" << originFile << " orR=" << originRank
			//	<< " destF=" << destFile << " destR=" << destRank << " player=" << player << endl;
		}

		vector<char> forwardData;
		for (int i = searchCursor; i < data.size(); i++) {
			forwardData.push_back(data[i]);
		}

		// Parse the TM forward stack data
		for (int i = 0; i < forwardData.size(); i += 5) {
			int originFile = forwardData[i];
			int originRank = forwardData[i + 1];
			int destFile = forwardData[i + 2];
			int destRank = forwardData[i + 3];
			int player = forwardData[i + 4];

			Move* move = new Move(player, new Position(originFile, originRank), new Position(destFile, destRank));

			this->tm->pushMoveForward(move);

			//cout << "Read a forward stack elem: orF=" << originFile << " orR=" << originRank
			//	<< " destF=" << destFile << " destR=" << destRank << " player=" << player << endl;
		}

		savefile.close();
	}
	else {
		return false;
	}
	this->playerTurn = 1;

	this->scorePlayer1 = 0;
	this->scorePlayer2 = 0;

	this->inGame = true;
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
			if (piece->pieceName() == "Knight") letter = 'N';
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
		for (auto move : forwardMoves) {
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
