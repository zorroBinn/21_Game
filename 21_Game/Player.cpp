#include "Player.h"

Player::Player(std::string playerName)
{
	name = playerName;
}

void Player::takeCard(const Card& card)
{
	hand.push_back(card);
}

int Player::calculatePoints() const
{
	//todo реализовать понижение очков для каждого туза в руке, если случился перебор
	int total = 0;
	for (const auto& card : hand) {
		total += card.getPoints();
	}
	return total;
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
