
#include <array>
#include <time.h>
#include "GameManager.h";
int main()
{
	srand(time(0));
	TeamManager teammanager;
	PlayerManager playermanager;
	HeroManager heromanager;
	Team teamone, teamtwo;
	Session session;
	GameManager gamemanager;
	Player players[10];
	Player pone[5], ptwo[5];
	Hero heroes[10];
	Hero hone[5], htwo[5];
	
	heroes[0] = heromanager.CreateHero(50, 55, "Young Sorcerrer", heroes[0]);
	heroes[1] = heromanager.CreateHero(100, 30, "Warrior", heroes[1]);
	heroes[2] = heromanager.CreateHero(120, 25, "Fighter", heroes[2]);
	heroes[3] = heromanager.CreateHero(200, 5, "Giant", heroes[3]);
	heroes[4] = heromanager.CreateHero(50, 50, "Sniper", heroes[4]);
	heroes[5] = heromanager.CreateHero(40, 60, "Mage", heroes[5]);
	heroes[6] = heromanager.CreateHero(35, 75, "Higher Mage", heroes[6]);
	heroes[7] = heromanager.CreateHero(80, 35, "Shooter", heroes[7]);
	heroes[8] = heromanager.CreateHero(20, 120, "Dark sorcerrer", heroes[8]);
	heroes[9] = heromanager.CreateHero(70, 15, "Weapon carrier", heroes[9]);
	for (int i = 0; i < 10; i++) {
		players[i] = playermanager.CreatePlayer(players[i], i);

		}
    while (session.StartTime() == true) {
		const int k = 10;
		int m[k];
		int v[k];
		for (int i = 0; i < k; i++)
		{
			while (true) {
				int a = 0;
				m[i] = 1 + rand() % k;
				for (int j = 0; j < i; j++) {
					if (m[j] != m[i]) a++;
				}
				if (a == i) break;
			}
			while (true) {
				int b = 0;
				v[i] = 1 + rand() % k;
				for (int j = 0; j < i; j++) {
					if (v[j] != v[i]) b++;
				}
				if (b == i) break;
			}
			players[i] = playermanager.SetId(players[i], m[i]);
			heroes[i] = heromanager.SetId(heroes[i], v[i]);
		}
		int j = 0;
		int d = 0;
		for (int i = 0; i < 10; i++) {
			if (players[i].id <= 5) {
				pone[j] = players[i];
				j++;
			}
			else {
				ptwo[d] = players[i];
				d++;
			}
		}
		j = 0; d = 0;
		for (int i = 0; i < 10; i++) {
			if (heroes[i].id <= 5) {
				hone[j] = heroes[i];
				j++;
			}
			else {
				htwo[d] = heroes[i];
				d++;
			}
		}
		std::string name1, name2;
		std::cout << "First team name: ";
		std::cin >> name1;
		teamone = teammanager.GenerateNewTeam(pone, hone, name1);
		std::cout << "Second team name: ";
		std::cin >> name1;
		teamtwo = teammanager.GenerateNewTeam(ptwo, htwo, name1);
		session.TeamOne(teamone);
		session.TeamTwo(teamtwo);
		j = 0;
		if (session.CalculateWinner() == true) {
			for (int i = 0; i < 10; i++) {
				if (players[i].id <= 5) {
					players[i].Rank += 25;
					session.winner.player[j].Rank = players[i].Rank;
					j++;
				}
				else {
					players[i].Rank -= 25;
				}
			}
		}
		else for (int i = 0; i < 10; i++) {
			if (players[i].id <= 5) {
				players[i].Rank -= 25;
			}
			else {
				players[i].Rank += 25;
				session.winner.player[j].Rank = players[i].Rank;
				j++;
			}
		}
		gamemanager.PerformGameSession(session);
	}
	gamemanager.Info();
}


