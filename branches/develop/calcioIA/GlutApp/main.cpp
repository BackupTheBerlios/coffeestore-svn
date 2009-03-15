#include <Game.h>
#include <Field.h>
#include <GameConfiguration.h>
#include <DummyTeam.h>
#include <NullTeam.h>

#include "Application.h"
#include "GLDraw.h"
#include "UserDrivenTeam.h"

class MyApplication : public Application
{
public:
	MyApplication(int width, int height)
		:	Application(width, height),
			_field(_gameConfiguration.fieldWidth(), _gameConfiguration.fieldHeight(), _gameConfiguration.boxWidthPct(), _gameConfiguration.boxHeightPct()),
			_game(_field, _userDrivenTeamFactory, _nullTeamFactory)
			//_game(_field, _nullTeamFactory, _userDrivenTeamFactory) // inverted keys
			//_game(_field, _tm1, _tm2)
	{
	
	}
	
	virtual void display()
	{
		_draw.draw(_game);
	}

	virtual void update() 
	{	
		_game.update();
	}

	virtual void keyboard(unsigned char key)
	{
		if (key == 27)
			exit(0);
	}

	virtual void specialKeyDown(SpecialKey specialKey)
	{
		_userDrivenTeamFactory.onSpecialKeyDown(specialKey);
	}

	virtual void specialKeyUp(SpecialKey specialKey)
	{
		_userDrivenTeamFactory.onSpecialKeyUp(specialKey);
	}

private:
	GameConfiguration _gameConfiguration;
	Field _field;
	UserDrivenTeamFactory _userDrivenTeamFactory;
	NullTeamFactory _nullTeamFactory;
	//DummyTeamFactory _tm1;
	//DummyTeamFactory _tm2;
	Game _game;
	GLDraw _draw;
};

int main(int argc,char** argv)
{
	MyApplication app(800, 500);
	app.initialize(argc, argv);
	return 0;
}
