#include "pch.h"
#include "..\21_Game\Deck.cpp"
using namespace std;

TEST(DeckTest, deckSimpleCreation) {
    Deck* deck = new Deck();
    ASSERT_NE(deck, nullptr);
    delete deck;
}

TEST(DeckTest, deckGetSizeTest) {
    Deck deck;
    EXPECT_EQ(deck.getSize(), 36);
}