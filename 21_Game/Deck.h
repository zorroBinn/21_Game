#pragma once
#include "Card.h"
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <random>

class Deck
{
private:
	std::vector<Card> cards;
	unsigned short currentCardIndex = 0;

public:
	Deck();

	void shuffle();
	int getSize() const;
	Card dealCard();
};

