/**
 * @file Game.h
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief High-level game overview and management.
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once
#include <string>
#include "../Board/Board.h"

class TimeMachine;

using namespace std;

/**
 * @brief Game class
 * 
 */
class Game {
private:
	Board* board;
	TimeMachine* tm;
	int scorePlayer1;
	int scorePlayer2;
	unsigned char playerTurn;
	void _printStatus();
	bool inGame = false;

public:
	void _printBoard();
	void reset();
	/**
	 * @brief Construct a new Game object
	 * 
	 */
	Game();

	/**
	 * @brief Starts a new game
	 * 
	 * @return true If successful
	 * @return false If something went wrong
	 */
	bool New();

	/**
	 * @brief Loads a game from a savefile
	 * 
	 * @param filename The name of the file
	 * @return true If successful
	 * @return false If something went wrong
	 */
	bool Load(string filename);

	/**
	 * @brief Saves the current game state into a file
	 * 
	 * @param filename The name of the file
	 * @return true If successful
	 * @return false If something went wrong
	 */
	bool Save(string filename);

	/**
	 * @brief Moves a piece on the board
	 * 
	 * @param player The player that makes the move (1 or 2)
	 * @param origin The origin of the moving piece
	 * @param destination The destination of the piece
	 * @param addToTimeMachine Whether the move is going to be added to the Time Machine
	 * 						   Defaults to true. This is in order not to add again moves
	 * 						   while playing back moves with the Time Machine.
	 * @return true If successful
	 * @return false If something went wrong
	 */
	bool movePiece(int player, string origin, string destination, bool addToTimeMachine = true);

	/**
	 * @brief Get the game score
	 * 
	 * @return pair<int, int> Pair of ints, first is player 1, second is player 2
	 */
	pair<int, int> getScore();

	/**
	 * @brief Get the Available Moves for a piece
	 * 		  The original intent of this is to provide a way to display the available moves to the user.
	 * 
	 * @param pos The position of the piece
	 * @return vector<Position*> The positions a piece can move to
	 */
	vector<Position*> getAvailableMoves(Position* pos);

	/**
	 * @brief Get which player is currently playing
	 * 
	 * @return int 
	 */
	int getPlayer();

	/**
	 * @brief Goes back one move
	 * 
	 * @return true 
	 * @return false 
	 */
	bool goBack();

	/**
	 * @brief Goes one move forward, if currently time travelling
	 * 
	 * @return true 
	 * @return false 
	 */
	bool goForward();
};
