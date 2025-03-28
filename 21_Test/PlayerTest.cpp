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
    delete player1, player2, player3;
}