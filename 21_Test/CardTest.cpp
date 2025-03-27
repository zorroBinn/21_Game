#include "pch.h"
#include "..\21_Game\Card.cpp"
using namespace std;

TEST(CardTest, CardSimpleCreation) {
    Card* card = new Card();
    ASSERT_NE(card, nullptr);
    delete card;
}

TEST(CardTest, heartsSixCardCreation) {
    Card* card = new Card(Card::Suit::Hearts, Card::Rank::Six);
    ASSERT_NE(card, nullptr);
    delete card;
}

TEST(CardTest, diamondsSevenCardCreation) {
    Card* card = new Card(Card::Suit::Diamonds, Card::Rank::Seven);
    ASSERT_NE(card, nullptr);
    delete card;
}

TEST(CardTest, ñlubsEightCardCreation) {
    Card* card = new Card(Card::Suit::Clubs, Card::Rank::Eight);
    ASSERT_NE(card, nullptr);
    delete card;
}

TEST(CardTest, spadesNineCardCreation) {
    Card* card = new Card(Card::Suit::Spades, Card::Rank::Nine);
    ASSERT_NE(card, nullptr);
    delete card;
}

TEST(CardTest, heartsTenCardCreation) {
    Card* card = new Card(Card::Suit::Hearts, Card::Rank::Ten);
    ASSERT_NE(card, nullptr);
    delete card;
}
