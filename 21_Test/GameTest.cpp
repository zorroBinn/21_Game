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

TEST(GameTest, gameAddAndGetThreePlayersTest) {
    Game game;

    game.addPlayer(Player("name1"));
    game.addPlayer(Player("name2"));
    game.addPlayer(Player("name3"));
    const auto& players = game.getPlayers();

    EXPECT_EQ(players.size(), 3) << "Не 3 игрока";
    EXPECT_EQ(players[0].getName(), "name1") << "Имя первого игрока не совпало";
    EXPECT_EQ(players[1].getName(), "name2") << "Имя второго игрока не совпало";
    EXPECT_EQ(players[2].getName(), "name3") << "Имя третьего игрока не совпало";
}