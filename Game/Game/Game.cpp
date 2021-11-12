
#include <time.h>
#include "GameManager.h";

int main()
{
	srand(time(0));
	//initialising variables
	TeamManager teammanager;
	PlayerManager playermanager;
	HeroManager heromanager;
	Team teamone, teamtwo;
	Session session;
	GameManager gamemanager;
	Player players[10], pone[5], ptwo[5];
	Hero heroes[10], hone[5], htwo[5];
	//creating heroes 
	heroes[0] = heromanager.CreateHero(50, 55, 1, "Young_Sorcerrer", heroes[0]);
	heroes[1] = heromanager.CreateHero(100, 30, 2, "Warrior", heroes[1]);
	heroes[2] = heromanager.CreateHero(120, 25, 3, "Fighter", heroes[2]);
	heroes[3] = heromanager.CreateHero(200, 5, 4, "Giant", heroes[3]);
	heroes[4] = heromanager.CreateHero(50, 50, 5, "Sniper", heroes[4]);
	heroes[5] = heromanager.CreateHero(40, 60, 6, "Mage", heroes[5]);
	heroes[6] = heromanager.CreateHero(35, 75, 7, "Higher_Mage", heroes[6]);
	heroes[7] = heromanager.CreateHero(80, 35, 8, "Shooter", heroes[7]);
	heroes[8] = heromanager.CreateHero(20, 120, 9, "Dark_sorcerrer", heroes[8]);
	heroes[9] = heromanager.CreateHero(70, 15, 10, "Weapon_carrier", heroes[9]);
	//creating players
	for (int i = 0; i < 10; i++) {
		players[i] = playermanager.SetId(players[i], i + 1);

	}
	for (int i = 0; i < 10; i++) {
		players[i] = playermanager.CreatePlayer(players[i], i);

		}
	//session loop
    while (session.StartTime() == true) {
		//randomly putting players to the teams
		int m = 0, k = 0, d = 0;
		for (int i = 0; i < 10; i++) {
			m = rand() % 2; //if m = 0, put player to the first team, if m = 1 to the second
			if (m == 0 && k < 5) {
				pone[k] = players[i];
				k++;
			}
			else if (m == 1 && d < 5) {
				ptwo[d] = players[i];
				d++;
			}
			else i--;
		}
		//randomly putting heroes to the teams
		m = 0; k = 0; d = 0;
		for (int i = 0; i < 10; i++) {
			m = rand() % 2;  //same random as for players
			if (m == 0 && k < 5) {
				hone[k] = heroes[i];
				k++;
			}
			else if (m == 1 && d < 5) {
				htwo[d] = heroes[i];
				d++;
			}
			else i--;
		}
		//generating teams
		std::string name1, name2;
		std::cout << "First team name: ";
		std::cin >> name1;
		teamone = teammanager.GenerateNewTeam(pone, hone, name1);
		std::cout << "Second team name: ";
		std::cin >> name1;
		teamtwo = teammanager.GenerateNewTeam(ptwo, htwo, name1);
		//saving teams to session
		session.TeamOne(teamone);
		session.TeamTwo(teamtwo);
		//calculating winner, addind and subtracting points
		//if first team win
		if (session.CalculateWinner() == true) {
			for (int i = 0; i < 10; i++) {
				for (int k = 0; k < 5; k++) {
					if (players[i].id == teamone.player[k].id) {
						players[i].Rank += 25;
						session.winner.player[k].Rank = players[i].Rank;
					}
					if (players[i].id == teamtwo.player[k].id) {
						players[i].Rank -= 25;
					}
				}

			}
		}
		//if second team win
		else for (int i = 0; i < 10; i++) {
			for (int k = 0; k < 5; k++) {
				if (players[i].id == teamone.player[k].id) {
					players[i].Rank -= 25;
				}
				if (players[i].id == teamtwo.player[k].id) {
					players[i].Rank += 25;
					session.winner.player[k].Rank = players[i].Rank;
				}
			}
		}
		//saving session to the sessions list
		gamemanager.PerformGameSession(session);
	}
	//showing info about winner team
	gamemanager.Info();
	//showing info about players and heroes by name and id
	std::string name;
	std::cout << "\n\nType player's name to check his info: " << std::endl;
	std::cin >> name;
	playermanager.ShowPlayerInfo(playermanager.GetPlayerByName(players,name));
	std::cout << "\n\nType hero's name to check his info: " << std::endl;
	std::cin >> name;
	heromanager.ShowHeroInfo(heromanager.GetHeroByName(heroes, name));
	int id;
	std::cout << "\n\nType player's id to check his info: " << std::endl;
	std::cin >> id;
	playermanager.ShowPlayerInfo(playermanager.GetPlayerById(players, id));
	std::cout << "\n\nType hero's id to check his info: " << std::endl;
	std::cin >> id;
	heromanager.ShowHeroInfo(heromanager.GetHeroById(heroes, id));

	return 0;
}


