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
	static int tmp_iteration = 0;
	int fieldwidth = 3;
	int numberofcolumns = 3;
	while (numberofcolumns > 0) {
		while (fieldwidth > 0) {
			if (fieldwidth % 2 == 0) {
				//std::cout << tmp->GetPosition();
				switch (tmp->GetMarkedBy()) {
				case None:
					std::cout << tmp->GetPosition();
					break;
				case Player1:
					std::cout << 'x';
					break;
				case Player2:
					std::cout << 'o';
					break;
				}
				tmp++;
				tmp_iteration++;
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
	if (tmp_iteration >= 9) {
		tmp = p;
		tmp_iteration = 0;
	}
	return;
}

bool GameBoard::Update (int position, const std::string& playerName) {
	if (playerName == "player1"
	    && m_boardFields[position - 1].GetMarkedBy() == ::None) {
		m_boardFields[position - 1].SetMarkedBy(::Player1);
		for (int i = 0; i < 9; i++)
			std::cout << m_boardFields[i];
		return true;
	} else if (playerName == "player2"
		   && m_boardFields[position - 1].GetMarkedBy() == ::None) {
		m_boardFields[position - 1].SetMarkedBy(::Player2);
		for (int i = 0; i < 9; i++)
			std::cout << m_boardFields[i];
		return true;
	}
	return false;
}

bool GameBoard::GameOver (const std::string& name1, const std::string& name2) {
	if ((m_boardFields[0].GetMarkedBy() == m_boardFields[1].GetMarkedBy())
		&&
		(m_boardFields[1].GetMarkedBy() == m_boardFields[2].GetMarkedBy())
		&& (m_boardFields[0].GetMarkedBy() != None)) {
		if (m_boardFields[1].GetMarkedBy() == Player1) {
			std::cout << "0==1==2\n";
			std::cout << m_boardFields[0].GetPosition()
				<< "=="
				<< m_boardFields[1].GetPosition()
				<< "=="
				<< m_boardFields[2].GetPosition()
				<< "\n";
			std::cout << m_boardFields[0].GetMarkedBy()
				<< "=="
				<< m_boardFields[1].GetMarkedBy()
				<< "=="
				<< m_boardFields[2].GetMarkedBy()
				<< "\n";
			std::cout << name1 << " won !!!";
			return true;
		} else if (m_boardFields[1].GetMarkedBy() == Player2){
			std::cout << "0==1==2\n";
			std::cout << m_boardFields[0].GetPosition()
				<< "=="
				<< m_boardFields[1].GetPosition()
				<< "=="
				<< m_boardFields[2].GetPosition()
				<< "\n";
			std::cout << m_boardFields[0].GetMarkedBy()
				<< "=="
				<< m_boardFields[1].GetMarkedBy()
				<< "=="
				<< m_boardFields[2].GetMarkedBy()
				<< "\n";
			std::cout << name2 << " won !!!";
			return true;
		}
	}

	else if ((m_boardFields[0].GetMarkedBy() == m_boardFields[3].GetMarkedBy())
		&&
		(m_boardFields[3].GetMarkedBy() == m_boardFields[6].GetMarkedBy())
		 && (m_boardFields[0].GetMarkedBy()!= None)) {
		if (m_boardFields[0].GetMarkedBy() == Player1) {
			std::cout << "0==3==6\n";
			std::cout << m_boardFields[0].GetPosition()
				<< "=="
				<< m_boardFields[3].GetPosition()
				<< "=="
				<< m_boardFields[6].GetPosition()
				<< "\n";
			std::cout << m_boardFields[0].GetMarkedBy()
				<< "=="
				<< m_boardFields[3].GetMarkedBy()
				<< "=="
				<< m_boardFields[6].GetMarkedBy()
				<< "\n";
			std::cout << name1 << " won !!!";
			return true;
		} else if (m_boardFields[0].GetMarkedBy() == Player2){
			std::cout << "0==3==6\n";
			std::cout << m_boardFields[0].GetPosition()
				<< "=="
				<< m_boardFields[3].GetPosition()
				<< "=="
				<< m_boardFields[6].GetPosition()
				<< "\n";
			std::cout << m_boardFields[0].GetMarkedBy()
				<< "=="
				<< m_boardFields[3].GetMarkedBy()
				<< "=="
				<< m_boardFields[6].GetMarkedBy()
				<< "\n";
			std::cout << name2 << " won !!!";
			return true;
		}
	}

	else if ((m_boardFields[0].GetMarkedBy() == m_boardFields[4].GetMarkedBy())
		&&
		(m_boardFields[4].GetMarkedBy() == m_boardFields[8].GetMarkedBy())
		&& (m_boardFields[0].GetMarkedBy() != None)) {
		if (m_boardFields[0].GetMarkedBy() == Player1) {
			std::cout << "0==4==8\n";
			std::cout << m_boardFields[0].GetPosition()
				<< "=="
				<< m_boardFields[4].GetPosition()
				<< "=="
				<< m_boardFields[8].GetPosition()
				<< "\n";
			std::cout << m_boardFields[0].GetMarkedBy()
				<< "=="
				<< m_boardFields[4].GetMarkedBy()
				<< "=="
				<< m_boardFields[8].GetMarkedBy()
				<< "\n";
			std::cout << name1 << " won !!!";
			return true;
		} else if (m_boardFields[0].GetMarkedBy() == Player2){
			std::cout << "0==4==8\n";
			std::cout << m_boardFields[0].GetPosition()
				<< "=="
				<< m_boardFields[4].GetPosition()
				<< "=="
				<< m_boardFields[8].GetPosition()
				<< "\n";
			std::cout << m_boardFields[0].GetMarkedBy()
				<< "=="
				<< m_boardFields[4].GetMarkedBy()
				<< "=="
				<< m_boardFields[8].GetMarkedBy()
				<< "\n";
			std::cout << name2 << " won !!!";
			return true;
		}
	}

	else if ((m_boardFields[6].GetMarkedBy() == m_boardFields[7].GetMarkedBy())
		&&
		(m_boardFields[7].GetMarkedBy() == m_boardFields[8].GetMarkedBy())
		&& (m_boardFields[6].GetMarkedBy() != None)) {
		if (m_boardFields[7].GetMarkedBy() == Player1) {
			std::cout << "6==7==8\n";
			std::cout << m_boardFields[6].GetPosition()
				<< "=="
				<< m_boardFields[7].GetPosition()
				<< "=="
				<< m_boardFields[8].GetPosition()
				<< "\n";
			std::cout << m_boardFields[6].GetMarkedBy()
				<< "=="
				<< m_boardFields[7].GetMarkedBy()
				<< "=="
				<< m_boardFields[8].GetMarkedBy()
				<< "\n";
			std::cout << name1 << " won !!!";
			return true;
		} else if (m_boardFields[7].GetMarkedBy() == Player2){
			std::cout << "6==7==8\n";
			std::cout << m_boardFields[6].GetPosition()
				<< "=="
				<< m_boardFields[7].GetPosition()
				<< "=="
				<< m_boardFields[8].GetPosition()
				<< "\n";
			std::cout << m_boardFields[6].GetMarkedBy()
				<< "=="
				<< m_boardFields[7].GetMarkedBy()
				<< "=="
				<< m_boardFields[8].GetMarkedBy()
				<< "\n";
			std::cout << name2 << " won !!!";
			return true;
		}
	}

	else if ((m_boardFields[3].GetMarkedBy() == m_boardFields[4].GetMarkedBy())
		&&
		(m_boardFields[4].GetMarkedBy() == m_boardFields[5].GetMarkedBy())
		&& (m_boardFields[3].GetMarkedBy() != None)) {
		if (m_boardFields[4].GetMarkedBy() == Player1) {
			std::cout << "3==4==5\n";
			std::cout << m_boardFields[3].GetPosition()
				<< "=="
				<< m_boardFields[4].GetPosition()
				<< "=="
				<< m_boardFields[5].GetPosition()
				<< "\n";
			std::cout << m_boardFields[3].GetMarkedBy()
				<< "=="
				<< m_boardFields[4].GetMarkedBy()
				<< "=="
				<< m_boardFields[5].GetMarkedBy()
				<< "\n";
			std::cout << name1 << " won !!!";
			return true;
		} else if (m_boardFields[4].GetMarkedBy() == Player2){
			std::cout << "3==4==5\n";
			std::cout << m_boardFields[3].GetPosition()
				<< "=="
				<< m_boardFields[4].GetPosition()
				<< "=="
				<< m_boardFields[5].GetPosition()
				<< "\n";
			std::cout << m_boardFields[3].GetMarkedBy()
				<< "=="
				<< m_boardFields[4].GetMarkedBy()
				<< "=="
				<< m_boardFields[5].GetMarkedBy()
				<< "\n";
			std::cout << name2 << " won !!!";
			return true;
		}
	}

	else if ((m_boardFields[1].GetMarkedBy() == m_boardFields[4].GetMarkedBy())
		&&
		(m_boardFields[4].GetMarkedBy() == m_boardFields[7].GetMarkedBy())
		       && (m_boardFields[1].GetMarkedBy() != None)) {
		if (m_boardFields[4].GetMarkedBy() == Player1) {
			std::cout << "1==7==4\n";
			std::cout << m_boardFields[1].GetPosition()
				<< "=="
				<< m_boardFields[4].GetPosition()
				<< "=="
				<< m_boardFields[7].GetPosition()
				<< "\n";
			std::cout << m_boardFields[1].GetMarkedBy()
				<< "=="
				<< m_boardFields[4].GetMarkedBy()
				<< "=="
				<< m_boardFields[7].GetMarkedBy()
				<< "\n";
			std::cout << name1 << " won !!!";
			return true;
		} else if (m_boardFields[4].GetMarkedBy() == Player2){
			std::cout << "1==7==4\n";
			std::cout << m_boardFields[1].GetPosition()
				<< "=="
				<< m_boardFields[4].GetPosition()
				<< "=="
				<< m_boardFields[7].GetPosition()
				<< "\n";
			std::cout << m_boardFields[1].GetMarkedBy()
				<< "=="
				<< m_boardFields[4].GetMarkedBy()
				<< "=="
				<< m_boardFields[7].GetMarkedBy()
				<< "\n";
			std::cout << name2 << " won !!!";
			return true;
		}
	}

	else if ((m_boardFields[2].GetMarkedBy() == m_boardFields[5].GetMarkedBy())
		&&
		(m_boardFields[5].GetMarkedBy() == m_boardFields[8].GetMarkedBy())
		&& (m_boardFields[2].GetMarkedBy() != None)) {
		if (m_boardFields[5].GetMarkedBy() == Player1) {
			std::cout << "2==5==8\n";
			std::cout << m_boardFields[2].GetPosition()
				<< "=="
				<< m_boardFields[5].GetPosition()
				<< "=="
				<< m_boardFields[8].GetPosition()
				<< "\n";
			std::cout << m_boardFields[2].GetMarkedBy()
				<< "=="
				<< m_boardFields[5].GetMarkedBy()
				<< "=="
				<< m_boardFields[8].GetMarkedBy()
				<< "\n";
			std::cout << name1 << " won !!!";
			return true;
		} else if (m_boardFields[5].GetMarkedBy() == Player2){
			std::cout << "2==5==8\n";
			std::cout << m_boardFields[2].GetPosition()
				<< "=="
				<< m_boardFields[5].GetPosition()
				<< "=="
				<< m_boardFields[8].GetPosition()
				<< "\n";
			std::cout << m_boardFields[2].GetMarkedBy()
				<< "=="
				<< m_boardFields[5].GetMarkedBy()
				<< "=="
				<< m_boardFields[8].GetMarkedBy()
				<< "\n";
			std::cout << name1 <<  " won !!!";
			return true;
		}
	}

	else if ((m_boardFields[2].GetMarkedBy() == m_boardFields[4].GetMarkedBy())
		&&
		(m_boardFields[4].GetMarkedBy() == m_boardFields[6].GetMarkedBy())
		       && (m_boardFields[2].GetMarkedBy() != None)) {
		if (m_boardFields[4].GetMarkedBy() == Player1) {
			std::cout << "2=4=6\n";
			std::cout << m_boardFields[2].GetPosition()
				<< "=="
				<< m_boardFields[4].GetPosition()
				<< "=="
				<< m_boardFields[6].GetPosition()
				<< "\n";
			std::cout << m_boardFields[2].GetMarkedBy()
				<< "=="
				<< m_boardFields[4].GetMarkedBy()
				<< "=="
				<< m_boardFields[6].GetMarkedBy()
				<< "\n";
			std::cout << name1 << " won !!!";
			return true;
		} else if (m_boardFields[4].GetMarkedBy() == Player2){
			std::cout << "2=4=6\n";
			std::cout << m_boardFields[2].GetPosition()
				<< "=="
				<< m_boardFields[4].GetPosition()
				<< "=="
				<< m_boardFields[6].GetPosition()
				<< "\n";
			std::cout << m_boardFields[2].GetMarkedBy()
				<< "=="
				<< m_boardFields[4].GetMarkedBy()
				<< "=="
				<< m_boardFields[6].GetMarkedBy()
				<< "\n";
			std::cout << name2 << " won !!!";
			return true;
		}
	}

	return false;
}

bool GameBoard::IsDraw () {
	for (int i = 0; i < 9; i++)
		if (m_boardFields[i].GetMarkedBy() == None)
			return false;
	return true;
}
