#pragma once
#include<iostream>

class Hero
{
	int hp, dmg, id;
	std::string Name;
public:
	
	friend class HeroManager;
	friend class Session;
};

