#include "Game.h"

Game::Game()
{
}

void Game::setupGame()
{
	int numPlayers;
	std::cout << "������� ���������� ������� (2-4): ";
	std::cin >> numPlayers;

	while (numPlayers < 2 || numPlayers > 4) {
		std::cout << "������! ������� ����� �� 2 �� 4: ";
		std::cin >> numPlayers;
	}
	for (int i = 1; i <= numPlayers; i++) {
		std::string name;
		std::cin >> name;
		Player player(name);
		players.push_back(player);
	}

	//������ ��������� 2 ����� ������� ������
	for (auto& player : players) {
		player.takeCard(deck.dealCard());
		player.takeCard(deck.dealCard());
	}
}

void Game::determineWinner()
{
	int bestScore = 0;
	std::vector<Player*> winners;
	for (auto& player : players) {
		int score = player.calculatePoints();
		if (score > bestScore) {
			bestScore = score;
			winners.clear();
			winners.push_back(&player);
		}
	}
	std::cout << "����������(�): ";
	for (auto* winner : winners) {
		std::cout << winner->getName() << " ";
	}
	std::cout << "� " << bestScore << " ������!" << std::endl;
}

void Game::addPlayer(Player p)
{
	players.push_back(p);
}

std::vector<Player> Game::getPlayers() const
{
	return players;
}
