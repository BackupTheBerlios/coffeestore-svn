#include "PlayerAction.h"
#include "Convertion.h"

PlayerAction::PlayerAction(Team::Side side)
	:	_side(side)
{

}

void PlayerAction::doRun(const Vector& r)
{
	_run = Convertion::toAbsoultePosition(r, _side);
}

void PlayerAction::doKick(const Vector& k)
{
	_kick = Convertion::toAbsoultePosition(k, _side);
}

const Vector& PlayerAction::run() const
{
	return _run;
}

const Vector& PlayerAction::kick() const
{
	return _kick;
}
