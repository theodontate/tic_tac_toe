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

#include "Player.hpp"

Player::Player (std::string name, mark type) : m_name(name), m_type(type) {
}

std::string Player::GetName () {
	return m_name;
}

std::string Player::GetType () {
	if (m_type == Player1)
		return "player1";
	else if (m_type == Player2)
		return "player2";
	return "none";
}
