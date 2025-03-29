#include "pch.h"
#include "..\21_Game\Game.cpp"
using namespace std;

TEST(GameTest, gameSimpleCreation) {
    Game* game = new Game();
    ASSERT_NE(game, nullptr);
    delete game;
}

TEST(GameTest, gameAddAndGetPlayers) {
    Game game;

    game.addPlayer(Player("Alice"));
    game.addPlayer(Player("Bob"));

    EXPECT_EQ(game.getPlayers().size(), 2) << "Не 2 игрока";
}