/*
 * Copyright (C) 2016  Narayanan, Naveen "zerous" theodontate@outlook.com
 * Author: Narayanan, Naveen "zerous" theodontate@outlook.com
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "GameBoard.hpp"
#include "Player.hpp"
#include <iostream>

int main (int argc, char** argv) {
	GameBoard board;
	GameBoard::DisplayGameBoard();
	Player player1("player1");
	Player player2("player2");
	bool gameplay = true;

	int tmp = 1;
	int position = 0;
	while (gameplay) {
		if (tmp % 2 == 0) {
			std::cout << "Player1 please enter your move : ";
			std::cin >> position;
			board.update(position, player1.GetName());
			board.DisplayGameBoard();
		}
		else {
			std::cout << "Player2 please enter your move : ";
			std::cin >> position;
			board.update(position, player2.GetName());
			board.DisplayGameBoard();
		}

	}

	return 0;
}
