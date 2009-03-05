#ifndef DRAW_H
#define DRAW_H

class Ball;
class Team;
class Player;
class Field;
class Game;

class Draw
{
public:
	virtual ~Draw() {}
	virtual void draw(const Ball& ball) = 0;
	virtual void draw(const Team& team) = 0;
	virtual void draw(const Player& player,const bool sightdir = false) = 0;
	virtual void draw(const Field& field) = 0;
	virtual void draw(const Game& game) = 0;
};

#endif
