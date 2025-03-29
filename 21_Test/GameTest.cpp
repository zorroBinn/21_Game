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

TEST(GameTest, gameSetupGameWithTwoPlayerCheckPlayersTest) {
    //Подмена ввода
    istringstream input("2\nname1\nname2\n");
    cin.rdbuf(input.rdbuf());

    Game game;
    game.setupGame();

    const auto& players = game.getPlayers();
    EXPECT_EQ(players.size(), 2) << "setupGame должен создать 2 игрока";
    EXPECT_EQ(players[0].getName(), "name1");
    EXPECT_EQ(players[1].getName(), "name2");

    cin.rdbuf(nullptr);
}

TEST(GameTest, gameSetupGameWithThreePlayerCheckPlayersTest) {
    //Подмена ввода
    istringstream input("3\nname1\nname2\nname3\n");
    cin.rdbuf(input.rdbuf());

    Game game;
    game.setupGame();

    const auto& players = game.getPlayers();
    EXPECT_EQ(players.size(), 3) << "setupGame должен создать 3 игрока";
    EXPECT_EQ(players[0].getName(), "name1");
    EXPECT_EQ(players[1].getName(), "name2");
    EXPECT_EQ(players[2].getName(), "name3");

    cin.rdbuf(nullptr);
}

TEST(GameTest, setupGameValidInputAndCheckFourPlayersTest) {
    istringstream input("1\n5\n4\nname1\nname2\nname3\nname4\n");
    cin.rdbuf(input.rdbuf());

    Game game;
    game.setupGame();
    
    const auto& players = game.getPlayers();
    ASSERT_EQ(players.size(), 4);
    EXPECT_EQ(players[0].getName(), "name1");
    EXPECT_EQ(players[1].getName(), "name2");
    EXPECT_EQ(players[2].getName(), "name3");
    EXPECT_EQ(players[3].getName(), "name4");
}

TEST(GameTest, setupGameInitialCardsTest) {
    istringstream input("2\nname1\nname2\n");
    cin.rdbuf(input.rdbuf());

    Game game;
    game.setupGame();

    const auto& players = game.getPlayers();
    EXPECT_EQ(players[0].getHand().size(), 2);
    EXPECT_EQ(players[1].getHand().size(), 2);

    cin.rdbuf(nullptr);
}

TEST(GameTest, determineWinnerTwoPlayerSimpleTest) {
    Game game;
    Player pl1("name1");
    Player pl2("name2");
    pl1.takeCard(Card(Card::Suit::Hearts, Card::Rank::Ace));
    pl1.takeCard(Card(Card::Suit::Hearts, Card::Rank::Ten));
    pl2.takeCard(Card(Card::Suit::Spades, Card::Rank::Ten));
    pl2.takeCard(Card(Card::Suit::Spades, Card::Rank::Seven));
    game.addPlayer(pl1);
    game.addPlayer(pl2);

    //Перехват вывода в консоль
    ostringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());

    game.determineWinner();

    cout.rdbuf(old);

    string expectedOutput = "Победитель(и): name1 с 21 очками!\n";
    EXPECT_EQ(buffer.str(), expectedOutput);
}

TEST(GameTest, determineWinnerThreePlayerTest) {
    Game game;
    Player pl1("name1");
    Player pl2("name2");
    Player pl3("name3");
    pl1.takeCard(Card(Card::Suit::Hearts, Card::Rank::Ace));
    pl1.takeCard(Card(Card::Suit::Hearts, Card::Rank::Eight));
    pl2.takeCard(Card(Card::Suit::Spades, Card::Rank::Ten));
    pl2.takeCard(Card(Card::Suit::Spades, Card::Rank::Seven));
    pl3.takeCard(Card(Card::Suit::Clubs, Card::Rank::Ten));
    pl3.takeCard(Card(Card::Suit::Diamonds, Card::Rank::Ten));
    game.addPlayer(pl1);
    game.addPlayer(pl2);
    game.addPlayer(pl3);

    //Перехват вывода в консоль
    ostringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());

    game.determineWinner();

    cout.rdbuf(old);

    string expectedOutput = "Победитель(и): name3 с 20 очками!\n";
    EXPECT_EQ(buffer.str(), expectedOutput);
}

TEST(GameTest, determineWinnerTwoPlayerOverkillTest) {
    Game game;
    Player pl1("name1");
    Player pl2("name2");
    pl1.takeCard(Card(Card::Suit::Clubs, Card::Rank::Ten));
    pl1.takeCard(Card(Card::Suit::Hearts, Card::Rank::Ten));
    pl1.takeCard(Card(Card::Suit::Hearts, Card::Rank::Nine));
    pl2.takeCard(Card(Card::Suit::Spades, Card::Rank::Ten));
    pl2.takeCard(Card(Card::Suit::Spades, Card::Rank::Seven));
    pl2.takeCard(Card(Card::Suit::Spades, Card::Rank::Eight));
    game.addPlayer(pl1);
    game.addPlayer(pl2);

    //Перехват вывода в консоль
    ostringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());

    game.determineWinner();

    cout.rdbuf(old);

    string expectedOutput = "Никто не выиграл!\n";
    EXPECT_EQ(buffer.str(), expectedOutput);
}

TEST(GameTest, determineWinnerFourPlayerFirstAndThirdWonTest) {
    Game game;
    Player pl1("name1");
    Player pl2("name2");
    Player pl3("name3");
    Player pl4("name4");
    pl1.takeCard(Card(Card::Suit::Hearts, Card::Rank::Ace));
    pl1.takeCard(Card(Card::Suit::Hearts, Card::Rank::Eight));
    pl2.takeCard(Card(Card::Suit::Spades, Card::Rank::Six));
    pl3.takeCard(Card(Card::Suit::Clubs, Card::Rank::Ten));
    pl3.takeCard(Card(Card::Suit::Diamonds, Card::Rank::Nine));
    pl4.takeCard(Card(Card::Suit::Diamonds, Card::Rank::Ten));
    pl4.takeCard(Card(Card::Suit::Diamonds, Card::Rank::Eight));
    pl4.takeCard(Card(Card::Suit::Diamonds, Card::Rank::Six));
    game.addPlayer(pl1);
    game.addPlayer(pl2);
    game.addPlayer(pl3);

    //Перехват вывода в консоль
    ostringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());

    game.determineWinner();

    cout.rdbuf(old);

    string expectedOutput = "Победитель(и): name1 name3 с 19 очками!\n";
    EXPECT_EQ(buffer.str(), expectedOutput);
}

TEST(GameTest, determineWinnerCalledAfterPlayTest) {
    istringstream input("2\nname1\nname2\n");
    cin.rdbuf(input.rdbuf());

    Game game;
    game.setupGame();

    EXPECT_NO_THROW(game.play());
    EXPECT_NO_THROW(game.determineWinner());
    cin.rdbuf(nullptr);
}

TEST(GameTest, playCanShowCardActivePlayerTest) {
    Game game;
    Player pl1("name1");
    pl1.takeCard(Card(Card::Suit::Hearts, Card::Rank::Ace));
    pl1.takeCard(Card(Card::Suit::Hearts, Card::Rank::Eight));
    game.addPlayer(pl1);
    //Перехват вывода в консоль
    ostringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());

    game.play();

    cout.rdbuf(old);

    string expectedOutput = "Карты игрока name1: A_Черви 8_Черви (19)\n";
    EXPECT_EQ(buffer.str(), expectedOutput);
}

TEST(GameTest, playersCanTakeCardAndPassTest) {
    istringstream input("2\nname1\nname2\n");
    cin.rdbuf(input.rdbuf());

    Game game;
    game.setupGame();
    cin.rdbuf(nullptr);

    const auto& playersBefore = game.getPlayers();
    int before1 = playersBefore[0].getHand().size();
    int before2 = playersBefore[1].getHand().size();
    
    istringstream inputPlay("+\nn\n+\n+\nn\n");
    cin.rdbuf(inputPlay.rdbuf());

    game.play();

    const auto& playersAfter = game.getPlayers();
    int after1 = playersAfter[0].getHand().size();
    int after2 = playersAfter[1].getHand().size();
    EXPECT_EQ(after1 - before1, 1);
    EXPECT_EQ(after2 - before2, 2);
    cin.rdbuf(nullptr);
}