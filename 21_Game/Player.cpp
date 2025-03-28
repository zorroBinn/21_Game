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
    int total = 0, aceCount = 0;
    for (const auto& card : hand) {
        total += card.getPoints();
        if (card.getPoints() == 11) aceCount++;
    }

    //Если перебор и есть туз(ы), понижаем их стоимость с 11 до 1
    while (total > 21 && aceCount > 0) {
        total -= 10;
        aceCount--;
    }
    return total;
}

void Player::showHand() const
{
    std::cout << "Карты игрока " << name << ": ";
    for (const auto& card : hand) {
        card.print();
    }
    std::cout << "(" << calculatePoints() << ")" << std::endl;
}

std::string Player::getName() const
{
	return name;
}
