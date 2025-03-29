#include <Windows.h>
#include "Game.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Game game;
	game.setupGame();
	game.play();
	std::cout << std::endl << std::endl;
	game.determineWinner();
	return 0;
}