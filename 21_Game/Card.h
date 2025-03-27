#pragma once


class Card
{
public:
    enum class Suit { Hearts };
    enum class Rank { Six = 6 };

private:
    Suit suit; //�����
    Rank rank; //�����������

public:
    Card();
    Card(Suit s, Rank r);
};

