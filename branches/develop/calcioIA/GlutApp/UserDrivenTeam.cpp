#include "UserDrivenTeam.h"
#include "PlayerAction.h"

UserDrivenPlayer::UserDrivenPlayer()
	:	AbstractPlayer(Point(), 1), _specialKey(Application::SpecialKey_None)
{

}

void UserDrivenPlayer::run(const Perceptions& perceptions, PlayerAction& playerAction)
{
	switch (_specialKey)
	{
	case Application::SpecialKey_Up:
		playerAction.doRun(Vector(0,1));
		break;
	case Application::SpecialKey_Down:
		playerAction.doRun(Vector(0,-1));
		break;
	case Application::SpecialKey_Left:
		playerAction.doRun(Vector(-1,0));
		break;
	case Application::SpecialKey_Right:
		playerAction.doRun(Vector(1,0));
		break;
	default:
		break;
	}
}

void UserDrivenPlayer::onSpecialKeyDown(Application::SpecialKey specialKey)
{
	_specialKey = specialKey;
}

void UserDrivenPlayer::onSpecialKeyUp(Application::SpecialKey specialKey)
{
	_specialKey = Application::SpecialKey_None;
}

std::vector<AbstractPlayer*> UserDrivenTeamFactory::createPlayers()
{
	std::vector<AbstractPlayer*> res;
	res.push_back(&_player);
	return res;
}

void UserDrivenTeamFactory::destroyPlayers(std::vector<AbstractPlayer*>& plys)
{

}

void UserDrivenTeamFactory::onSpecialKeyDown(Application::SpecialKey specialKey)
{
	_player.onSpecialKeyDown(specialKey);
}

void UserDrivenTeamFactory::onSpecialKeyUp(Application::SpecialKey specialKey)
{
	_player.onSpecialKeyUp(specialKey);
}

