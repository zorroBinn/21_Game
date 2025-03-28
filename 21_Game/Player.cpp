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
	//todo ����������� ����������� ������� ����� ���� ���� � ����
	return hand.back().getPoints();
}

void Player::showHand() const
{
	//todo ����������� ����������� ����� ���� ������ � ��������� �����
	std::cout << "����� ������ ����: A_����� (11)" << std::endl;
}

std::string Player::getName() const
{
	return name;
}
