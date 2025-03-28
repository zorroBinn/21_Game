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

    //������������� ����� � �������
    ostringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());

    card.print();

    cout.rdbuf(old);

    EXPECT_FALSE(buffer.str().empty()) << "����� �� ��������";
}

TEST(DeckTest, dealUniqueCardsFromDeckTest) {
    Deck deck;
    set<string> uniqueCards;

    for (int i = 0; i < 36; ++i) {
        Card card = deck.dealCard();

        //�������� ������ � �������
        ostringstream buffer;
        streambuf* old = cout.rdbuf(buffer.rdbuf());

        card.print();

        cout.rdbuf(old);
        string cardStr = buffer.str();
        EXPECT_TRUE(uniqueCards.find(cardStr) == uniqueCards.end()) << "������ �����: " << cardStr; //���������, ��� ����� ���������
        uniqueCards.insert(cardStr);
    }

    //���������, ��� ���������� ���� 36
    EXPECT_EQ(uniqueCards.size(), 36) << "������ ���� ����� 36 ���������� ����!";
}

TEST(DeckTest, deckGetSizeAfterDealTest) {
    Deck deck;
    deck.dealCard();
    EXPECT_EQ(deck.getSize(), 35);
}

TEST(DeckTest, dealExceptionAfterOutOfCardTest) {
    Deck deck;
    for (int i = 0; i < 36; i++) {
        deck.dealCard();
    }
    EXPECT_THROW(deck.dealCard(), out_of_range);
}