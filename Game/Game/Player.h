#pragma once
#include <iostream>
#include <vector>
class Player
{
	
	std::string Name;
public:
	int id;
	int Rank = 0;
	friend class PlayerManager;
};

