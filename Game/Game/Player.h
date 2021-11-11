#pragma once
#include <iostream>
#include <vector>
class Player
{
	
	std::string Name;
public:
	int id, Rank = 0;
	friend class PlayerManager;
};

