#include "PlayerAction.h"
#include "Convertion.h"
#include "MathFun.h"

PlayerAction::PlayerAction(Team::Side side)
	:	_side(side),_run(0.0f,0.0f),_kick(0.0f,0.0f),_see(float(side) * Vector(1.0f,0.0f))
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

void PlayerAction::doTurnHead( const float angle )
{
	float rad = mathfun::deg2Rad(angle);
	float cosang = std::cos(rad);
	float sinang = std::sin(rad);
	_see = Vector(cosang * _see.x() - sinang * _see.y(),sinang * _see.x() + cosang * _see.y()).normalize();
}

const Vector& PlayerAction::sightDirection() const
{
	return _see;
}