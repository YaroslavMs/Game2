#pragma once
#include"HeroManager.h"
#include"PlayerManager.h"

class Team
{
	
	Hero hero[5];
	std::string name;
public:
	Player player[5];
	friend class TeamManager;
	friend class Session;
};

