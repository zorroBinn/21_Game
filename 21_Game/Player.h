#pragma once
#include <iostream>

class Player
{
private:
	std::string name;

public:
	Player(std::string playerName);

	std::string getName() const;
};

