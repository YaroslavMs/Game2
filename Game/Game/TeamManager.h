#pragma once
#include "Team.h"
class TeamManager
{
	Team team;
	PlayerManager playerman;
	HeroManager heroman;
public:
	Team GenerateNewTeam(Player a[5], Hero b[5], std::string name) {
		for (int i = 0; i < 5; i++) {
			team.player[i] = a[i];
			team.hero[i] = b[i];
		}
		team.name = name;
		return team;
	}
	void GetTeamInfo(Team team) {
		std::cout << "Team " << team.name << "\nPLayers and Heroes in the team: " << std::endl;
		for (int i = 0; i < 5; i++) {
			playerman.ShowPlayerInfo(team.player[i]);
			heroman.ShowHeroInfo(team.hero[i]);
		}
	}
};

