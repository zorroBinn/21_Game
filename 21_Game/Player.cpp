#include "Player.h"

Player::Player(std::string playerName)
{
	name = playerName;
}

std::string Player::getName() const
{
	return name;
}
