#pragma once
#include <iostream>
#include <vector>
class Player
{
	int id;
	std::string Name, Rank;
	friend class PlayerManager;
};

