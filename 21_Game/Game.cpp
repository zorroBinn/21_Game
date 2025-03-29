#include "Game.h"
using namespace std;

Game::Game()
{
}

void Game::setupGame()
{
	int numPlayers;
	cout << "������� ���������� ������� (2-4): ";
	cin >> numPlayers;

	while (numPlayers < 2 || numPlayers > 4) {
		cout << "������! ������� ����� �� 2 �� 4: ";
		cin >> numPlayers;
	}
	for (int i = 1; i <= numPlayers; i++) {
		string name;
		cout << "������� ��� ������ " << i << ": ";
		cin >> name;
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
	system("cls");
	for (auto& player : players) {
		while (true) {
			player.showHand();
			cout << player.getName() << ", ������ ����� �����? (\"+\"/\"n\"): ";
			char choice;
			cin >> choice;

			if (choice == '+') {
				player.takeCard(deck.dealCard());
				if (player.calculatePoints() > 21) {
					cout << player.getName() << " ��������!" << endl;
					break;
				}
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
	vector<Player*> winners;
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
		cout << "����� �� �������!" << endl;
	}
	else {
		cout << "����������(�): ";
		for (auto* winner : winners) {
			cout << winner->getName() << " ";
		}
		cout << "� " << bestScore << " ������!" << endl;
	}
}

void Game::addPlayer(Player p)
{
	players.push_back(p);
}

vector<Player> Game::getPlayers() const
{
	return players;
}
