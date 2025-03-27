#include "Card.h"

Card::Card()
{
}

/// <summary>
/// ����������� � �����������
/// </summary>
/// <param name="s"> ����� </param>
/// <param name="r"> ����������� </param>
Card::Card(Suit s, Rank r)
{
	//todo ����������� ���������� ����� ����� � �����������
}

int Card::getPoints() const
{
    switch (rank) {
    case Rank::Ace: return 11;
    case Rank::King: return 4;
    case Rank::Queen: return 3;
    case Rank::Jack: return 2;
    default: return static_cast<int>(rank); //6-10 �� ��������
    }
}
