/**
 * @file main.cpp
 * @author Konstantinos Kamaropoulos (k@kamaropoulos.com)
 * @brief ChessCPP entry file.
 * @version 0.1
 * @date 2019-07-06
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Game/Game.h"

 /**
  * @brief Entry point.
  * 
  * This was only intended for debugging purposes but because of time limitation,
  * I wasn't able to implement a proper UI.
  * I was working on an ncurses based UI but up to the projects deadline, it wasn't
  * ready to turn in. So I sent this one instead. It's fully functional but might
  * be buggy since it takes direct input from the user, whereas the UI would be 
  * calling the methods with standard and checked input.
  *
  * @return int
  */
int main() {
	// Initialize the game object
	Game* game = new Game();

	// Strings for the two commands
	string cmd1, cmd2;

	cout << "Command: ";

	// Read commands
	cin >> cmd1 >> cmd2;

	// Create a new game
	if ((cmd1 == "new") && (cmd2 == "game")) {
		game->New();
		goto play;
	}

	// Load a file
	if (cmd1 == "load") {
		game->Load(cmd2);
		goto play;
	}
play:
	// First print of the board
	// _printBoard was only intended for internal testing
	// but was opened up for the purpose of this debugging "UI" only.
	game->_printBoard();

	string from, to;
	while (true) {
		bool move = false;

		do {
			cout << "Player " << game->getPlayer() << ": ";
			cin >> from >> to;
			// Load a file
			if (from == "load") {
				game->Load(to);
				break;
			}
			// Save into a file. Will only work if it's player 1's turn.
			if (from == "save") {
				game->Save(to);
				break;
			}
			// Ends the game
			if ((from == "end") && (to == "game")) {
				return 0;
			}
			// Goes one move back
			if ((from == "go") && (to == "back")) {
				game->goBack();
			}
			else {
				// goes one move forward
				if ((from == "go") && (to == "forward")) {
					game->goForward();
				}
				else {
					// If from and to weren't holding a command, issue the move
					// This can throw as it's currently not checking the input.
					move = game->movePiece(game->getPlayer(), from, to);
				}
			}
		} while (!move);

		// Print the score for debugging
		cout << game->getScore().first << " - " << game->getScore().second << endl;
	}
	return 0;
}