#include "Deck.h"

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
	//todo реализовать полноценный возврат текущего кол-ва карт в колоде
	return 36;
}

Card Deck::dealCard()
{
	//todo реализовать исключение, если требуют возврат карты >36 
	return cards[currentCardIndex++];
}
