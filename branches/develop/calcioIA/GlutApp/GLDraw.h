#ifndef GLDRAW_H
#define GLDRAW_H

#include "Draw.h"

class Point;
class Line;
class Rectangle;

class GLDraw : public Draw
{
public:
	void draw(const Ball& ball);
	void draw(const Team& team);
	void draw(const Player& player);
	void draw(const Field& field);
	void draw(const Game& game);

private:
	void drawFilledCircle(const Point& point, float radius);
	void drawWire(const Rectangle& rectangle);
	void draw(const Line& line);
};

#endif
