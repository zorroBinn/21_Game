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

TEST(DeckTest, deckDealCardTest) {
    Deck deck;
    Card card = deck.dealCard();

    //Перехватываем вывод в консоль
    ostringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());

    card.print();

    cout.rdbuf(old);

    EXPECT_FALSE(buffer.str().empty()) << "Карта не вывелась";
}