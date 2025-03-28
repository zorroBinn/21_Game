#include "Player.h"

Player::Player(std::string playerName)
{
	name = playerName;
}

void Player::takeCard(const Card& card)
{
	//todo реализовать запоминание карты в руке
}

int Player::calculatePoints() const
{
	return 11;
}

void Player::showHand() const
{
	//todo реализовать полноценный вывод карт игрока с подсчётом очков
	std::cout << "Карты игрока Иван: A_Черви (11)" << std::endl;
}

std::string Player::getName() const
{
	return name;
}
