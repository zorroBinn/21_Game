#include "Deck.h"
#include <stdexcept>

Deck::Deck()
{
	//todo реализовать перемешивание карт
	for (int s = 0; s < 4; s++) { // Перебираем все масти
		for (int r = 6; r <= 14; r++) { // От 6 до туза (Ace = 14)
			cards.emplace_back(static_cast<Card::Suit>(s), static_cast<Card::Rank>(r));
		}
	}
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
