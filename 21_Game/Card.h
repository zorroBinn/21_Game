#pragma once


class Card
{
public:
    enum class Suit { Hearts, Diamonds };
    enum class Rank { Six = 6, Seven };

private:
    Suit suit; //�����
    Rank rank; //�����������

public:
    Card();
    Card(Suit s, Rank r);
};

