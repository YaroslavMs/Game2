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
		std::cout << "###############\nPlayer info:\nName: " << a.Name << "\nRank: " << a.Rank << "\nId: " << a.id << std::endl;
	}
	Player GetPlayerByName(Player a[10], std::string name) {
		for (int i = 0; i < 10; i++) {
			if (a[i].Name == name) {
				return a[i];
			}
		}
		std::cout << "Name not found. Showing player with id 1" << std::endl;
		return a[0];
	}
	Player GetPlayerById(Player a[10], int id) {
		for (int i = 0; i < 10; i++) {
			if (a[i].id == id) {
				return a[i];
			}
		}
		std::cout << "Name not found. Showing player with id 1" << std::endl;
		return a[0];
	}
};

