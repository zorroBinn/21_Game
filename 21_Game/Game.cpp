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

void Game::play()
{
	//todo � ����� ���������� ����������(-��)
	//��������� ����� �����, ���� ��� ��������
	for (auto& player : players) {
		system("cls");
		while (true) {
			player.showHand();
			std::cout << player.getName() << ", ������ ����� �����? (\"+\"/\"n\"): ";
			char choice;
			std::cin >> choice;

			if (choice == '+') {
				player.takeCard(deck.dealCard());
			}
			else if (choice == 'n') {
				break;
			}
		}
	}
}

void Game::determineWinner()
{
	int bestScore = 0;
	std::vector<Player*> winners;
	for (auto& player : players) {
		int score = player.calculatePoints();
		if (score > 21) continue;  //���� �������� - �����������
		if (score > bestScore) {
			bestScore = score;
			winners.clear();
			winners.push_back(&player);
		}
		else if (score == bestScore) {
			winners.push_back(&player);
		}
	}
	if (winners.empty()) {
		std::cout << "����� �� �������!" << std::endl;
	}
	else {
		std::cout << "����������(�): ";
		for (auto* winner : winners) {
			std::cout << winner->getName() << " ";
		}
		std::cout << "� " << bestScore << " ������!" << std::endl;
	}
}

void Game::addPlayer(Player p)
{
	players.push_back(p);
}

std::vector<Player> Game::getPlayers() const
{
	return players;
}
