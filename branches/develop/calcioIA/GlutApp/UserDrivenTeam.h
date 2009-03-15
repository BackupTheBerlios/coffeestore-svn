#ifndef USER_DRIVEN_TEAM_H
#define USER_DRIVEN_TEAM_H

#include <AbstractPlayer.h>
#include <AbstractPlayersFactory.h>

#include "Application.h"

class UserDrivenPlayer : public AbstractPlayer
{
public:
	UserDrivenPlayer();

	virtual void run(const Perceptions& perceptions, PlayerAction& playerAction);

	void onSpecialKeyDown(Application::SpecialKey specialKey);
	void onSpecialKeyUp(Application::SpecialKey specialKey);
private:
	Application::SpecialKey _specialKey;
};

class UserDrivenTeamFactory : public AbstractPlayersFactory
{
public:
	std::vector<AbstractPlayer*> createPlayers();
	void destroyPlayers(std::vector<AbstractPlayer*>& plys);

	void onSpecialKeyDown(Application::SpecialKey specialKey);
	void onSpecialKeyUp(Application::SpecialKey specialKey);
private:
	UserDrivenPlayer _player;
};

#endif
