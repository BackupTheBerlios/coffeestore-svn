#include "GameConfiguration.h"
#include "Configuration.h"
#include "TextStream.h"
#include <cassert>

GameConfiguration::GameConfiguration()
	:	_fieldWidthDefault(100),
		_fieldHeightDefault(100),
		_boxWidthPctDefault(30),
		_boxHeightPctDefault(50)
{
	TextFileStream fileStream("calcio.ini");
	assert(fileStream.exists());

	Configuration config(fileStream);
	_fieldWidth = config.getInteger("FieldWidth", _fieldWidthDefault);
	_fieldHeight = config.getInteger("FieldHeight", _fieldHeightDefault);
	_boxWidthPct = config.getInteger("BoxWidthPct", _boxWidthPctDefault);
	_boxHeightPct = config.getInteger("BoxHeightPct", _boxHeightPctDefault);
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
