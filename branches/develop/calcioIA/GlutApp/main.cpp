#include "Application.h"

#include "Game.h"
#include "DummyTeam.h"
#include "GLDraw.h"

class MyApplication : public Application
{
public:
	MyApplication(int width, int height)
		:	Application(width, height),
			_tm1(true), _tm2(false),
			_game(_tm1, _tm2)
	{
	
	}
	
	void display()
	{
		_draw.draw(_game);
	}

	void update() 
	{	
		_game.update();
	}

	void keyboard(unsigned char key)
	{
		if (key == 27)
			exit(0);
	}

private:
	DummyTeamFactory _tm1;
	DummyTeamFactory _tm2;
	Game _game;
	GLDraw _draw;
};

int main(int argc,char** argv)
{
	MyApplication app(800, 450);
	app.initialize(argc, argv);
	return 0;
}
