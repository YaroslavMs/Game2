#pragma once
#include<iostream>

class Hero
{
	int id, hp, dmg;
	std::string Name;
	friend class HeroManager;
	friend class Session;
};

