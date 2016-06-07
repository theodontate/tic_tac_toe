#include "Player.hpp"

Player::Player (std::string name) : m_name(name) {
}

std::string Player::GetName () {
	return m_name;
}
