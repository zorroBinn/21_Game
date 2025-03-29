#include "Game.h"

Game::Game()
{
}

void Game::setupGame()
{
	int numPlayers;
	std::cin >> numPlayers;
	std::string name1, name2;
	std::cin >> name1;
	std::cin >> name2;
	Player player1(name1);
	Player player2(name2);
	players.push_back(player1);
	players.push_back(player2);
}

void Game::addPlayer(Player p)
{
	players.push_back(p);
}

std::vector<Player> Game::getPlayers() const
{
	return players;
}
