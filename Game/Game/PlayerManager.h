#pragma once
#include"Player.h"

class PlayerManager
{
public:
	Player CreatePlayer(Player a,int i) {
		std::cout << "Type player's " << i + 1 <<" name: ";
		std::cin >> a.Name;
		return a;
	}
	Player SetId(Player a, int i) {
		a.id = i;
		return a;
	}
	Player DeletePlayer(Player a) {
		a.Name = "";
		a.Rank = 0;
		return a;
	}
	void ShowPlayerInfo(Player a) {
		std::cout << "###############\nPlayer info:\nName: " << a.Name << "\nRank: " << a.Rank << std::endl;
	}
};

