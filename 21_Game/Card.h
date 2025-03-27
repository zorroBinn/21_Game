#pragma once


class Card
{
public:
    enum class Suit { Hearts, Diamonds, Clubs, Spades };
    enum class Rank { Six = 6, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

private:
    Suit suit; //Масть
    Rank rank; //Достоинство

public:
    Card();
    Card(Suit s, Rank r);
};

