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

#ifndef id17598649397577
#define id17598649397577

#include "BoardField.hpp"
#include "Player.hpp"

class GameBoard {
	public:
		GameBoard ( );
		static void DisplayGameBoard ( );
		static void Update ( int position,
				     const std::string& playerName );
		static bool GameOver ( );

	private:
		static BoardField m_boardFields[9];
};

void printRow (BoardField* p);

#endif
