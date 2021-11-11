#pragma once
#include "TeamManager.h"
class Session
{
	Team one, two, winner;
public:
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
		 else std::cout << "Invalid option" << std::endl;
	   }
		return start;
	}
	void TeamOne(Team one) {
		this->one = one;
	}
	void TeamTwo(Team two) {
		this->two = two;
	}
	void CalculateWinner() {
		int hpone = 0, hptwo = 0;
		for (int i = 5; i < 5; i++) {
			hpone += (one.hero[i].hp - two.hero[i].dmg);
			hptwo += (two.hero[i].hp - one.hero[i].dmg);
		}
		if (hpone > hptwo) {
			winner = one;
		}
		if (hpone < hptwo) {
			winner = two;
		}
	}
	void Winner() {

	}
};

