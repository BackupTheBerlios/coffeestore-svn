#include "Perceptions.h"
#include "Team.h"
#include "Game.h"
#include "Player.h"

Perceptions::Perceptions(const Game& game,const Player& ply)
:_player(ply),_ball(initBall(game))
{
	initOpponentVect(game);
	initTeamMateVect(game);
}

const Point& Perceptions::ballPosition() const
{
	return _ball.position();
}

const Vector& Perceptions::ballDirection() const
{
	return _ball.direction();
}

const Perceptions::PerceivedPlayers& Perceptions::visibleTeamMate() const
{
	return _mate;
}

const Perceptions::PerceivedPlayers& Perceptions::visibleOpponent() const
{
	return _opp;
}

const Point& Perceptions::playerPosition() const
{
	return _player.position();
}

Ball Perceptions::initBall(const Game& game)
{
	Point p = 
	return Ball(game.side(_player.teamColor()) * game. 
}

void Perceptions::initOpponentVect(const Game& game)
{

}

void Perceptions::initTeamMateVect(const Game& game)
{

}