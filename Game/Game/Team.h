#pragma once
#include"HeroManager.h"
#include"PlayerManager.h"

class Team
{
	Player player[5];
	Hero hero[5];
	std::string name;
	friend class TeamManager;
	friend class Session;
};

