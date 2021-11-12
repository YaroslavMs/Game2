#pragma once
#include "TeamManager.h"
class Session
{
	TeamManager man;
	
public:
	Team one, two, winner, loser;
	bool StartTime() {
		 bool choose = false;
		 bool start = false;
		 while (choose == false){
			std::string yesno;
		 std::cout << "Start new session? y/n :" << std::endl;
		 std::cin >> yesno;
		 if (yesno == "y") {
			std::cout << "Starting Session..." << std::endl;
			start = true; choose = true;
		 }
		 if (yesno == "n") {
			std::cout << "Closing program..." << std::endl;
			choose = true;
		 }
		 if (yesno != "y" && yesno != "n") std::cout << "Invalid option" << std::endl;
	   }
		return start;
	}
	void TeamOne(Team one) {
		this->one = one;
	}
	void TeamTwo(Team two) {
		this->two = two;
	}
	bool CalculateWinner() {
		bool win1 = true;
		int hpone = 0, hptwo = 0;
		for (int i = 0; i < 5; i++) {
			hpone += (one.hero[i].hp - two.hero[i].dmg);
			hptwo += (two.hero[i].hp - one.hero[i].dmg);
		}
		if (hpone > hptwo) {
			winner = one;
			loser = two;
		}
		if (hpone < hptwo) {
			winner = two;
			loser = one;
			win1 = false;
		}
		return win1;
	}
	void Winner() {
		std::cout << "\n\nWinner" << std::endl;
		man.GetTeamInfo(winner);
	}
	void Loser() {
		std::cout << "\n\nLoser" << std::endl;
		man.GetTeamInfo(loser);
	}
};

