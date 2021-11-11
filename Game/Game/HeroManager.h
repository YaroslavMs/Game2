#pragma once
#include"Hero.h"
class HeroManager
{
public:
	Hero CreateHero(int hp, int dmg, std::string Name, Hero a) {
		a.hp = hp;
		a.dmg = dmg;
		a.Name = Name;
		return a;
	}
	Hero SetId(Hero a, int i) {
		a.id = i;
		return a;
	}
	Hero DeleteHero(Hero a) {
		a.hp = 0;
		a.dmg = 0;
		a.Name = "";
		return a;
	}
	void ShowHeroInfo(Hero a) {
		std::cout << "Hero info:\nName: " << a.Name << "\nHp: " << a.hp <<"\ndamage: " << a.dmg << std::endl;
	}
};

