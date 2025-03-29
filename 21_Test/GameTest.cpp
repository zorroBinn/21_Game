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

    EXPECT_EQ(game.getPlayers().size(), 2) << "�� 2 ������";
}

TEST(GameTest, gameAddAndGetThreePlayersTest) {
    Game game;

    game.addPlayer(Player("name1"));
    game.addPlayer(Player("name2"));
    game.addPlayer(Player("name3"));
    const auto& players = game.getPlayers();

    EXPECT_EQ(players.size(), 3) << "�� 3 ������";
    EXPECT_EQ(players[0].getName(), "name1") << "��� ������� ������ �� �������";
    EXPECT_EQ(players[1].getName(), "name2") << "��� ������� ������ �� �������";
    EXPECT_EQ(players[2].getName(), "name3") << "��� �������� ������ �� �������";
}

TEST(GameTest, gameSetupGameWithTwoPlayerCheckPlayersTest) {
    //������� �����
    istringstream input("2\nname1\nname2\n");
    cin.rdbuf(input.rdbuf());

    Game game;
    game.setupGame();

    const auto& players = game.getPlayers();
    EXPECT_EQ(players.size(), 2) << "setupGame ������ ������� 2 ������";
    EXPECT_EQ(players[0].getName(), "name1");
    EXPECT_EQ(players[1].getName(), "name2");

    cin.rdbuf(nullptr);
}