#pragma once
#include "Player.h"
#include <vector>

class Game
{
private:
	std::vector<Player> players;

public:
	Game();

	void setupGame();
	void addPlayer(Player p);
	std::vector<Player> getPlayers() const;
};

