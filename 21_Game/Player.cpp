#include "Player.h"
using namespace std;

Player::Player(string playerName)
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
    cout << "Карты игрока " << name << ": ";
    for (const auto& card : hand) {
        card.print();
    }
    cout << "(" << calculatePoints() << ")" << endl;
}

string Player::getName() const
{
	return name;
}

vector<Card> Player::getHand() const
{
    return hand;
}
