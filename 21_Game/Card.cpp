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
	//todo реализовать метод с полноценной выдачей очков карты по её достоинству
	return 6;
}
