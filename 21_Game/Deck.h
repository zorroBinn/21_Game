#pragma once
#include "Card.h"
#include <vector>
class Deck
{
private:
	std::vector<Card> cards;
	unsigned short currentCardIndex = 0;

public:
	Deck();

	int getSize() const;
	Card dealCard();
};

