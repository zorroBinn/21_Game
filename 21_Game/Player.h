#pragma once
#include <iostream>
#include <vector>
#include "Card.h"

class Player
{
private:
	std::string name;
	std::vector<Card> hand;

public:
	Player(std::string playerName);

	void takeCard(const Card& card);
	int calculatePoints() const;
	void showHand() const;
	std::string getName() const;
	std::vector<Card> getHand() const;
};

