#include "pch.h"
#include "..\21_Game\Player.cpp"
using namespace std;

TEST(PlayerTest, playerSimpleCreation) {
    Player* player = new Player("����");
    ASSERT_NE(player, nullptr);
    delete player;
}

TEST(PlayerTest, playerGetNameTest) {
    string name = "����";
    Player* player = new Player(name);
    EXPECT_EQ(player->getName(), name);
    delete player;
}

TEST(PlayerTest, playerGetUniqueNameTest) {
    string name1 = "name1";
    string name2 = "name1";
    string name3 = "name1";
    Player* player1 = new Player(name1);
    Player* player2 = new Player(name2);
    Player* player3 = new Player(name3);
    EXPECT_EQ(player1->getName(), name1) << "������ ��� �� �������";
    EXPECT_EQ(player2->getName(), name2) << "������ ��� �� �������";
    EXPECT_EQ(player3->getName(), name3) << "������ ��� �� �������";
    delete player1; 
    delete player2;
    delete player3;
}

TEST(PlayerTest, playerShowHandWithOneCardTest) {
    Player player("����");
    Card card1(Card::Suit::Hearts, Card::Rank::Ace);
    player.takeCard(card1);

    //�������� ������ � �������
    ostringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());

    player.showHand();

    cout.rdbuf(old);

    string expectedOutput = "����� ������ ����: A_����� (11)\n";
    EXPECT_EQ(buffer.str(), expectedOutput) << "����� showHand() �� ������������� ����������!";
}

TEST(PlayerTest, playerCalculatePointsOfOneCardTest) {
    Player player("����");
    Card card1(Card::Suit::Hearts, Card::Rank::Ace);
    player.takeCard(card1);
    EXPECT_EQ(player.calculatePoints(), 11);
}

TEST(PlayerTest, playerCalculatePointsOnOneCardOfAllCardsTest) {
    Player player1("name1");
    Player player2("name2");
    Player player3("name3");
    Player player4("name4");
    Player player5("name5");
    Player player6("name6");
    Player player7("name7");
    Player player8("name8");
    Player player9("name9");
    Card card1(Card::Suit::Hearts, Card::Rank::Ace);
    Card card2(Card::Suit::Hearts, Card::Rank::King);
    Card card3(Card::Suit::Hearts, Card::Rank::Queen);
    Card card4(Card::Suit::Hearts, Card::Rank::Jack);
    Card card5(Card::Suit::Hearts, Card::Rank::Ten);
    Card card6(Card::Suit::Hearts, Card::Rank::Nine);
    Card card7(Card::Suit::Hearts, Card::Rank::Eight);
    Card card8(Card::Suit::Hearts, Card::Rank::Seven);
    Card card9(Card::Suit::Hearts, Card::Rank::Six);
    player1.takeCard(card1);
    EXPECT_EQ(player1.calculatePoints(), 11);
    player2.takeCard(card2);
    EXPECT_EQ(player2.calculatePoints(), 4);
    player3.takeCard(card3);
    EXPECT_EQ(player3.calculatePoints(), 3);
    player4.takeCard(card4);
    EXPECT_EQ(player4.calculatePoints(), 2);
    player5.takeCard(card5);
    EXPECT_EQ(player5.calculatePoints(), 10);
    player6.takeCard(card6);
    EXPECT_EQ(player6.calculatePoints(), 9);
    player7.takeCard(card7);
    EXPECT_EQ(player7.calculatePoints(), 8);
    player8.takeCard(card8);
    EXPECT_EQ(player8.calculatePoints(), 7);
    player9.takeCard(card9);
    EXPECT_EQ(player9.calculatePoints(), 6);
}

TEST(PlayerTest, playerCalculatePointsOfThreeCardsTest) {
    Player player("����");
    Card card1(Card::Suit::Hearts, Card::Rank::Ace);
    Card card2(Card::Suit::Hearts, Card::Rank::King);
    Card card3(Card::Suit::Hearts, Card::Rank::Queen);
    player.takeCard(card1);
    player.takeCard(card2);
    player.takeCard(card3);
    EXPECT_EQ(player.calculatePoints(), 18);
}

TEST(PlayerTest, playerCalculatePointsWithTwoAcesForReductionTest) {
    Player player("����");
    Card card1(Card::Suit::Hearts, Card::Rank::Ace);
    Card card2(Card::Suit::Hearts, Card::Rank::Ten);
    Card card3(Card::Suit::Hearts, Card::Rank::Seven);
    Card card4(Card::Suit::Clubs, Card::Rank::Ace);
    player.takeCard(card1);
    player.takeCard(card2);
    player.takeCard(card3);
    player.takeCard(card4);
    EXPECT_EQ(player.calculatePoints(), 19);
}

TEST(PlayerTest, playerShowHandWithFourCardsTest) {
    Player player("����");
    Card card1(Card::Suit::Hearts, Card::Rank::Ace);
    Card card2(Card::Suit::Diamonds, Card::Rank::King);
    Card card3(Card::Suit::Clubs, Card::Rank::Queen);
    Card card4(Card::Suit::Spades, Card::Rank::Jack);
    player.takeCard(card1);
    player.takeCard(card2);
    player.takeCard(card3);
    player.takeCard(card4);
    //�������� ������ � �������
    ostringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());

    player.showHand();

    cout.rdbuf(old);

    string expectedOutput = "����� ������ ����: A_����� K_����� Q_������ J_���� (20)\n";
    EXPECT_EQ(buffer.str(), expectedOutput) << "����� showHand() �� ������������� ����������!";
}