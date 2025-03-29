#include "Game.h"

Game::Game()
{
}

void Game::setupGame()
{
	int numPlayers;
	std::cout << "Введите количество игроков (2-4): ";
	std::cin >> numPlayers;

	while (numPlayers < 2 || numPlayers > 4) {
		std::cout << "Ошибка! Введите число от 2 до 4: ";
		std::cin >> numPlayers;
	}
	for (int i = 1; i <= numPlayers; i++) {
		std::string name;
		std::cin >> name;
		Player player(name);
		players.push_back(player);
	}

	//Раздаём стартовые 2 карты каждому игроку
	for (auto& player : players) {
		player.takeCard(deck.dealCard());
		player.takeCard(deck.dealCard());
	}
}

void Game::play()
{
	//todo в конце определять победителя(-ей)
	//запретить брать карты, если уже перебрал
	for (auto& player : players) {
		system("cls");
		while (true) {
			player.showHand();
			std::cout << player.getName() << ", хотите взять карту? (\"+\"/\"n\"): ";
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
		if (score > 21) continue;  //Если перебрал - исключается
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
		std::cout << "Никто не выиграл!" << std::endl;
	}
	else {
		std::cout << "Победитель(и): ";
		for (auto* winner : winners) {
			std::cout << winner->getName() << " ";
		}
		std::cout << "с " << bestScore << " очками!" << std::endl;
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
