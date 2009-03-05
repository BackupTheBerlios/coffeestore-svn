#include "GameConfiguration.h"
#include "Configuration.h"
#include "TextStream.h"
#include <cassert>

GameConfiguration::GameConfiguration()
	:	_fieldWidthDefault(100),
		_fieldHeightDefault(100)
{
	TextFileStream fileStream("calcio.ini");
	assert(fileStream.exists());

	Configuration config(fileStream);
	_fieldWidth = config.getInteger("FieldWidth", _fieldWidthDefault);
	_fieldHeight = config.getInteger("FieldHeight", _fieldHeightDefault);
}

int GameConfiguration::fieldWidth() const
{
	return _fieldWidth;
}

int GameConfiguration::fieldHeight() const
{
	return _fieldHeight;
}

