#include "Player.h"

Player::Player(std::string playerName)
{
	name = playerName;
}

void Player::takeCard(const Card& card)
{
	//todo ����������� ����������� ����� � ����
}

int Player::calculatePoints() const
{
	return 11;
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
