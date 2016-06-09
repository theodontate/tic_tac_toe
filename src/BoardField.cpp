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

#include "BoardField.hpp"
#include <iostream>

int BoardField::s_count = 1;

BoardField::BoardField () : m_position(s_count++), m_markedBy(None) {
		std::cout << "Log : \n"
			<< "BoardField::BoardField()\n"
			<< "m_position : " << m_position << std::endl
			<< "m_markedBy : " << m_markedBy << std::endl;
}

void BoardField::Display () {
		std::cout << " position : " << m_position << std::endl
			<< "markedBy : " << m_markedBy << std::endl;
}

int BoardField::GetPosition () {
	return m_position;
}

void BoardField::SetMarkedBy (mark m) {
	m_markedBy = m;
}

mark BoardField::GetMarkedBy () {
	return m_markedBy;
}
