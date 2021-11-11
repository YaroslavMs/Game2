#pragma once
#include<iostream>

class Hero
{
	int hp, dmg;
	std::string Name;
public:
	int id;
	friend class HeroManager;
	friend class Session;
};

