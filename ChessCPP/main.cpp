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
	string from, to;
	while (true) {
		bool move = false;

		do {
			cout << "Player " << game->getPlayer() << ": ";
			cin >> from >> to;
			if ((from == "end") && (to == "game")) {
				goto end;
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

end:;

	//auto movesA = game->getAvailableMoves(new Position("h2"));
	//for (auto move : movesA) {
	//	cout << "move for h2: " << move->toString() << endl;
	//}
}