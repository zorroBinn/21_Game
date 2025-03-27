#pragma once


class Card
{
public:
    enum class Suit { Hearts, Diamonds, Clubs };
    enum class Rank { Six = 6, Seven, Eight };

private:
    Suit suit; //�����
    Rank rank; //�����������

public:
    Card();
    Card(Suit s, Rank r);
};

