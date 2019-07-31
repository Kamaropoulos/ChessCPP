/**
 * @file Move.h
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief Piece movement descriptor
 * @version 0.1
 * @date 2019-07-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#include "../Position/Position.h"
#include "../Piece/Piece.h"

enum MoveResult { MOVE, TAKE, PROMOTION };

class Move {
private:
	Position* origin;
	Position* destination;
	int player;

public:
	/**
	 * @brief Construct a new Move object
	 * 
	 * @param player 
	 * @param origin 
	 * @param destination 
	 */
	Move(int player, Position* origin, Position* destination);

	/**
	 * @brief Get the Origin 
	 * 
	 * @return Position* 
	 */
	Position* getOrigin();

	/**
	 * @brief Get the Destination
	 * 
	 * @return Position* 
	 */
	Position* getDestination();

	/**
	 * @brief Get the Player that made the move
	 * 
	 * @return int 
	 */
	int getPlayer();
};
