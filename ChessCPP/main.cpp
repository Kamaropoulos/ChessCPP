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
  * @return int
  */
int main() {
	Game* game = new Game();
	string cmd1, cmd2;
	cout << "Command: ";
	cin >> cmd1 >> cmd2;
	if ((cmd1 == "new") && (cmd2 == "game")) {
		game->New();
		goto play;
	}
	if (cmd1 == "load") {
		game->Load(cmd2);
		goto play;
	}
play:
	game->_printBoard();
	string from, to;
	while (true) {
		bool move = false;

		do {
			cout << "Player " << game->getPlayer() << ": ";
			cin >> from >> to;
			if (from == "load") {
				game->Load(to);
				break;
			}
			if (from == "save") {
				game->Save(to);
				break;
			}
			if ((from == "end") && (to == "game")) {
				return 0;
			}
			if ((from == "go") && (to == "back")) {
				game->goBack();
			}
			else {
				if ((from == "go") && (to == "forward")) {
					game->goForward();
				}
				else {
					move = game->movePiece(game->getPlayer(), from, to);
				}
			}
		} while (!move);

		cout << game->getScore().first << " - " << game->getScore().second << endl;
	}
	return 0;
}