#include "pch.h"
#include "..\21_Game\Player.cpp"
using namespace std;

TEST(PlayerTest, playerSimpleCreation) {
    Player* player = new Player("Иван");
    ASSERT_NE(player, nullptr);
    delete player;
}

TEST(PlayerTest, playerGetNameTest) {
    string name = "Иван";
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
    EXPECT_EQ(player1->getName(), name1) << "Первое имя не совпало";
    EXPECT_EQ(player2->getName(), name2) << "Второе имя не совпало";
    EXPECT_EQ(player3->getName(), name3) << "Третье имя не совпало";
    delete player1; 
    delete player2;
    delete player3;
}

TEST(PlayerTest, playerShowHandWithOneCardTest) {
    Player player("Иван");
    Card card1(Card::Suit::Hearts, Card::Rank::Ace);
    player.takeCard(card1);

    //Перехват вывода в консоль
    ostringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());

    player.showHand();

    cout.rdbuf(old);

    string expectedOutput = "Карты игрока Иван: A_Черви (11)\n";
    EXPECT_EQ(buffer.str(), expectedOutput) << "Вывод showHand() не соответствует ожидаемому!";
}