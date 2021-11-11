#pragma once
#include "Session.h"
#include <list>
class GameManager
{
	std::list<Session> GameSessions;
public:
	void PerformGameSession(Session session) {
		GameSessions.push_back(session);
	}
	void Info() {
		for (auto i : GameSessions) {
			i.Winner();
		}
	}
};

