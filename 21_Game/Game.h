#pragma once
#include "Player.h"
#include <vector>
#include "Deck.h"

class Game
{
private:
	std::vector<Player> players;
	Deck deck;

public:
	Game();

	void setupGame();
	void play();
	void determineWinner();
	void addPlayer(Player p);
	std::vector<Player> getPlayers() const;
};

