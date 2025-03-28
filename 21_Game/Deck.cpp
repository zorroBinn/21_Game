#include "Deck.h"

Deck::Deck()
{
	//todo ����������� ������������� ����
	for (int s = 0; s < 4; s++) { // ���������� ��� �����
		for (int r = 6; r <= 14; r++) { // �� 6 �� ���� (Ace = 14)
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
	//todo ����������� ����������, ���� ������� ������� ����� >36 
	return cards[currentCardIndex++];
}
