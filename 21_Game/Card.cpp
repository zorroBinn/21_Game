#include "Card.h"
using namespace std;

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
    suit = s;
    rank = r;
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

void Card::print() const
{
    string suits[] = { "_�����", "_�����", "_������", "_����" };
    string ranks[] = { "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    cout << ranks[static_cast<int>(rank) - 6] << suits[static_cast<int>(suit)] << " ";
}
