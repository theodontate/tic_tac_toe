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
#include <iostream>

BoardField GameBoard::m_boardFields[9];

GameBoard::GameBoard () {
}

void GameBoard::DisplayGameBoard () {
	BoardField* p = m_boardFields;
	int tmp = 3;
	while ((tmp--) > 0) {
		printRow(p);
		if (tmp > 0)
			std::cout << "---+---+---\n";
	}
}

void printRow (BoardField* p) {
	static BoardField* tmp = p;
	int fieldwidth = 3;
	int numberofcolumns = 3;
	while (numberofcolumns > 0) {
		while (fieldwidth > 0) {
			if (fieldwidth % 2 == 0) {
				std::cout << tmp->GetPosition();
				tmp++;
			}
			else
				std::cout << " ";
			--fieldwidth;
		}
		if (numberofcolumns > 1)
			std::cout << "|";
		fieldwidth = 3;
		--numberofcolumns;
	}
	std::cout << std::endl;
	return;
}

void GameBoard::update (int position, const std::string& playerName) {
	if (playerName == "player1") {
		m_boardFields[position].SetMarkedBy(mark::Player1);
	} else {
		m_boardFields[position].SetMarkedBy(mark::Player2);
	}

}
