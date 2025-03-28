#include "Deck.h"

Deck::Deck()
{
}

int Deck::getSize() const
{
	//todo реализовать полноценный возврат текущего кол-ва карт в колоде
	return 36;
}

Card Deck::dealCard()
{
	//todo реализовать полноценный возврат карты из конца колоды
	return Card(Card::Suit::Spades, Card::Rank::Ace);
}
