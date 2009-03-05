#ifndef GAME_CONFIGURATION_H
#define GAME_CONFIGURATION_H

class GameConfiguration
{
public:
	GameConfiguration();

	int fieldWidth() const;
	int fieldHeight() const;

private:
	int _fieldWidthDefault;
	int _fieldHeightDefault;

	int _fieldWidth;
	int _fieldHeight;
};

#endif
