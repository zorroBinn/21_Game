#pragma once
#include "Card.h"

class Deck
{
public:
	Deck();

	int getSize() const;
	Card dealCard();
};

