#include "GameConfiguration.h"
#include "Configuration.h"
#include "TextStream.h"
#include <cassert>

GameConfiguration::GameConfiguration()
{
	setDefaults();

	TextFileStream fileStream("calcio.ini");
	assert(fileStream.exists());

	Configuration config(fileStream);
	_fieldWidth = config.getInteger("FieldWidth", _fieldWidthDefault);
	_fieldHeight = config.getInteger("FieldHeight", _fieldHeightDefault);
	_boxWidthPct = config.getInteger("BoxWidthPct", _boxWidthPctDefault);
	_boxHeightPct = config.getInteger("BoxHeightPct", _boxHeightPctDefault);
}

GameConfiguration::GameConfiguration(int fieldWidth, int fieldHeight, int boxWidthPct, int boxHeighPct)
	:	_fieldWidth(fieldWidth),
		_fieldHeight(fieldHeight),
		_boxWidthPct(boxWidthPct),
		_boxHeightPct(boxHeighPct)
{
	setDefaults();
}

void GameConfiguration::setDefaults()
{
	_fieldWidthDefault = 100;
	_fieldHeightDefault = 100;
	_boxWidthPctDefault = 30;
	_boxHeightPctDefault = 50;
}

int GameConfiguration::fieldWidth() const
{
	return _fieldWidth;
}

int GameConfiguration::fieldHeight() const
{
	return _fieldHeight;
}

int GameConfiguration::boxWidthPct() const
{
	return _boxWidthPct;
}

int GameConfiguration::boxHeightPct() const
{
	return _boxHeightPct;
}
