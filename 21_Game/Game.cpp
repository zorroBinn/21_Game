#include "Game.h"

Game::Game()
{
}

void Game::addPlayer(Player p)
{
	//todo реализовать полноценное добавление игроков
}

std::vector<Player> Game::getPlayers() const
{
	//todo реализовать полноценный возврат вектора игроков
	std::vector<Player> pl = { Player("Alice"), Player("Bob") };
	return pl;
}
