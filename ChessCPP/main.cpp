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
		bool move1 = false;
		bool move2 = false;
		do {
			cout << "Player 1: ";
			cin >> from >> to;
			if ((from == "end") && (to == "game")) {
				goto end;
			}
			if ((from == "go") && (to == "back")) {
				game->goBack();
			}
			else {
				move1 = game->movePiece(1, from, to);
			}
		} while (!move1);
		cout << game->getScore().first << " - " << game->getScore().second << endl;
		do {
			cout << "Player 2: ";
			cin >> from >> to;
			if ((from == "end") && (to == "game")) {
				goto end;
			}
			if ((from == "go") && (to == "back")) {
				game->goBack();
			}
			else {
				move2 = game->movePiece(2, from, to);
			}
		} while (!move2);
		cout << game->getScore().first << " - " << game->getScore().second << endl;
	}

end:;

	//auto movesA = game->getAvailableMoves(new Position("h2"));
	//for (auto move : movesA) {
	//	cout << "move for h2: " << move->toString() << endl;
	//}
}