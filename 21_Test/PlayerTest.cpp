#include "pch.h"
#include "..\21_Game\Player.cpp"
using namespace std;

TEST(PlayerTest, playerSimpleCreation) {
    Player* player = new Player("����");
    ASSERT_NE(player, nullptr);
    delete player;
}