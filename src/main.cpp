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
	std::string player1name, player2name;
	std::cout << "Enter the name of Player1 : ";
	std::cin >> player1name;
	std::cout << "\nEnter the name of Player2 : ";
	std::cin >> player2name;
	Player player1(player1name,Player1);
	Player player2(player2name,Player2);
	bool gameplay = true;
	bool isdraw = false;

	int tmp = 1;
	int position = 0;
	//std::cout << "\033[2J\033[1;1H";
	GameBoard::DisplayGameBoard();
	while (gameplay) {
		if (tmp % 2 == 0) {
			std::cout << "\n" << player1name << " please enter your move : ";
			std::cin >> position;
			if(!board.Update(position, player1.GetType()))
				continue;
			//std::cout << "\033[2J\033[1;1H";
			board.DisplayGameBoard();
			if (board.GameOver(player1name, player2name))
				break;
			if (board.IsDraw()) {
				isdraw = true;
				break;
			}
			tmp++;
		}
		else {
			std::cout << "\n" << player2name << " please enter your move : ";
			std::cin >> position;
			board.Update(position, player2.GetType());
			//std::cout << "\033[2J\033[1;1H";
			board.DisplayGameBoard();
			if (board.GameOver(player1name, player2name))
				break;
			if (board.IsDraw()) {
				isdraw = true;
				break;
			}
			tmp++;
		}

	}
	if (isdraw) {
		std::cout << "Game is a draw.\n";
	}

	return 0;
}
