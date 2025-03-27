#pragma once


class Card
{
public:
    enum class Suit { Hearts, Diamonds, Clubs, Spades };
    enum class Rank { Six = 6, Seven, Eight, Nine, Ten, Jack };

private:
    Suit suit; //�����
    Rank rank; //�����������

public:
    Card();
    Card(Suit s, Rank r);
};

