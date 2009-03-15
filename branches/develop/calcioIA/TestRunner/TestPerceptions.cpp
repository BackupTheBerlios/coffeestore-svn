#include <UnitTest++.h>
#include <Perceptions.h>
#include <NullTeam.h>
#include <Game.h>
#include <Player.h>
#include <Field.h>

class PositionPctFixture
{
public:
	PositionPctFixture()
		: _field(150, 100, 0, 0)
		, _game(_field, _nullTeamFactory, _nullTeamFactory)
		, _player(_nullPlayer)
	{
	
	}

	~PositionPctFixture()
	{
	
	}
	
	Perceptions::PositionPct getPositionPct(Team::Color color, const Point& playerPosition)
	{
		_player.position() = playerPosition;
		Perceptions perceptions(_game, color, _player);
		return perceptions.playerPositionPct();
	}

private:
	NullTeamFactory _nullTeamFactory;
	NullPlayer _nullPlayer;
	Field _field;
	Game _game;
	Player _player;
};

TEST_FIXTURE(PositionPctFixture, TestPositionRedPctCenter)
{
	Perceptions::PositionPct positionPct = getPositionPct(Team::Color_RED, Point());
	CHECK_EQUAL(50, positionPct.width());
	CHECK_EQUAL(50, positionPct.height());
}

TEST_FIXTURE(PositionPctFixture, TestPositionBluePctCenter)
{
	Perceptions::PositionPct positionPct = getPositionPct(Team::Color_BLUE, Point());
	CHECK_EQUAL(50, positionPct.width());
	CHECK_EQUAL(50, positionPct.height());
}

TEST_FIXTURE(PositionPctFixture, TestPositionRedPctOutside)
{
	Perceptions::PositionPct positionPct = getPositionPct(Team::Color_RED, Point(160, 110));
	CHECK_EQUAL(156, positionPct.width());
	CHECK_EQUAL(160, positionPct.height());
}

TEST_FIXTURE(PositionPctFixture, TestPositionBluePctOutside)
{
	Perceptions::PositionPct positionPct = getPositionPct(Team::Color_BLUE, Point(160, 110));
	CHECK_EQUAL(-56, positionPct.width());
	CHECK_EQUAL(-60, positionPct.height());
}

TEST_FIXTURE(PositionPctFixture, TestPositionRedPctInside)
{
	Perceptions::PositionPct positionPct = getPositionPct(Team::Color_RED, Point(20, 20));
	CHECK_EQUAL(63, positionPct.width());
	CHECK_EQUAL(70, positionPct.height());
}

TEST_FIXTURE(PositionPctFixture, TestPositionBluePctInside)
{
	Perceptions::PositionPct positionPct = getPositionPct(Team::Color_BLUE, Point(20, 20));
	CHECK_EQUAL(36, positionPct.width());
	CHECK_EQUAL(30, positionPct.height());
}
