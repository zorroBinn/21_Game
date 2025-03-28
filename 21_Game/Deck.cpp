#include "Deck.h"
#include <stdexcept>
#include <algorithm>
#include <random>

Deck::Deck()
{
	for (int s = 0; s < 4; s++) { // Перебираем все масти
		for (int r = 6; r <= 14; r++) { // От 6 до туза (Ace = 14)
			cards.emplace_back(static_cast<Card::Suit>(s), static_cast<Card::Rank>(r));
		}
	}
	shuffle();
}

void Deck::shuffle()
{
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(cards.begin(), cards.end(), g);
	currentCardIndex = 0;
}

int Deck::getSize() const
{
	return cards.size() - currentCardIndex;
}

Card Deck::dealCard()
{
	if (getSize() > 0) {
		return cards[currentCardIndex++];
	}
	throw std::out_of_range("Карта не может быть роздана — колода пуста!");
}
