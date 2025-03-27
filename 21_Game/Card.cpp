#include "Card.h"

Card::Card()
{
}

/// <summary>
/// Конструктор с параметрами
/// </summary>
/// <param name="s"> Масть </param>
/// <param name="r"> Достоинство </param>
Card::Card(Suit s, Rank r)
{
	//todo реализовать присвоение карте масти и достоинства
}

int Card::getPoints() const
{
    switch (rank) {
    case Rank::Ace: return 11;
    case Rank::King: return 4;
    case Rank::Queen: return 3;
    case Rank::Jack: return 2;
    default: return static_cast<int>(rank); //6-10 по номиналу
    }
}
