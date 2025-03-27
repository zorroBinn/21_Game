#pragma once


class Card
{
public:
    enum class Suit { Hearts };
    enum class Rank { Six = 6 };

private:
    Suit suit; //Масть
    Rank rank; //Достоинство

public:
    Card();
    Card(Suit s, Rank r);
};

