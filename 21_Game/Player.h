#pragma once
#include <iostream>
#include "Card.h"

class Player
{
private:
	std::string name;

public:
	Player(std::string playerName);

	void takeCard(const Card& card);
	int calculatePoints() const;
	void showHand() const;
	std::string getName() const;
};

