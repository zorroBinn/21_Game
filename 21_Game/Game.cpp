#include "Game.h"

Game::Game()
{
}

void Game::addPlayer(Player p)
{
	//todo ����������� ����������� ���������� �������
}

std::vector<Player> Game::getPlayers() const
{
	//todo ����������� ����������� ������� ������� �������
	std::vector<Player> pl = { Player("Alice"), Player("Bob") };
	return pl;
}
