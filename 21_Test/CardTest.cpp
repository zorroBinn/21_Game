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

TEST(CardTest, �lubsEightCardCreation) {
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

TEST(CardTest, heartsJackCardCreation) {
    Card* card = new Card(Card::Suit::Hearts, Card::Rank::Jack);
    ASSERT_NE(card, nullptr);
    delete card;
}

TEST(CardTest, heartsQueenCardCreation) {
    Card* card = new Card(Card::Suit::Hearts, Card::Rank::Queen);
    ASSERT_NE(card, nullptr);
    delete card;
}

TEST(CardTest, heartsKingCardCreation) {
    Card* card = new Card(Card::Suit::Hearts, Card::Rank::King);
    ASSERT_NE(card, nullptr);
    delete card;
}

TEST(CardTest, heartsAceCardCreation) {
    Card* card = new Card(Card::Suit::Hearts, Card::Rank::Ace);
    ASSERT_NE(card, nullptr);
    delete card;
}

TEST(CardTest, clubsSixCardGetPoints) {
    EXPECT_EQ(Card(Card::Suit::Clubs, Card::Rank::Six).getPoints(), 6);
}

TEST(CardTest, anyCardGetPoints) {
    EXPECT_EQ(Card(Card::Suit::Clubs, Card::Rank::Six).getPoints(), 6);
    EXPECT_EQ(Card(Card::Suit::Clubs, Card::Rank::Seven).getPoints(), 7);
    EXPECT_EQ(Card(Card::Suit::Clubs, Card::Rank::Eight).getPoints(), 8);
    EXPECT_EQ(Card(Card::Suit::Clubs, Card::Rank::Nine).getPoints(), 9);
    EXPECT_EQ(Card(Card::Suit::Clubs, Card::Rank::Ten).getPoints(), 10);
    EXPECT_EQ(Card(Card::Suit::Clubs, Card::Rank::Jack).getPoints(), 2);
    EXPECT_EQ(Card(Card::Suit::Clubs, Card::Rank::Queen).getPoints(), 3);
    EXPECT_EQ(Card(Card::Suit::Clubs, Card::Rank::King).getPoints(), 4);
    EXPECT_EQ(Card(Card::Suit::Clubs, Card::Rank::Ace).getPoints(), 11);
}



