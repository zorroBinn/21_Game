#pragma once
#include "Player.h"
#include <vector>

class Game
{
public:
	Game();

	void addPlayer(Player p);
	std::vector<Player> getPlayers() const;
};

