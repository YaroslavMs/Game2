#pragma once
#include"Hero.h"
class HeroManager
{
public:
	void CreateHero(int hp, int dmg, std::string Name, Hero a) {
		a.hp = hp;
		a.dmg = dmg;
		a.Name = Name;
	}
	void DeleteHero(Hero a) {
		a.hp = 0;
		a.dmg = 0;
		a.Name = "";
	}
	void ShowHeroInfo(Hero a) {
		std::cout << "###############\nHero info:\nName: " << a.Name << "\nHp: " << a.hp <<"\ndamage: " << a.dmg << std::endl;
	}
};

