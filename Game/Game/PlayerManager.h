#pragma once
#include"Player.h"

class PlayerManager
{
public:
	void CreatePlayer(Player a) {
		std::cout << "Type player's name: ";
		std::cin >> a.Name;
	}
	void DeletePlayer(Player a) {
		a.Name = "";
		a.Rank = "";
	}
	void ShowPlayerInfo(Player a) {
		std::cout << "###############\nPlayer info:\nName: " << a.Name << "\nRank: " << a.Rank << std::endl;
	}
};

