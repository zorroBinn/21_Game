#include "Deck.h"

Deck::Deck()
{
}

int Deck::getSize() const
{
	//todo ����������� ����������� ������� �������� ���-�� ���� � ������
	return 36;
}

Card Deck::dealCard()
{
	//todo ����������� ����������� ������� ����� �� ����� ������
	return Card(Card::Suit::Spades, Card::Rank::Ace);
}
