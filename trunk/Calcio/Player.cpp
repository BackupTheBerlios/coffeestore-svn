#include "Player.h"

Player::Player(const Point& p, int n, Team::Color teamColor)
	:	_p(p), _radius(3), _number(n), _teamColor(teamColor)
{

}

Point& Player::position()
{
	return _p;
}

const Point& Player::position() const
{
	return _p;
}

float Player::radius() const
{
	return _radius;
}

int Player::number() const
{
	return _number;
}

Team::Color Player::teamColor() const
{
	return _teamColor;
}

void Player::run(const Perceptions& p, PlayerAction& playerAction)
{

}
