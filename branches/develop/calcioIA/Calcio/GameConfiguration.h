#ifndef GAME_CONFIGURATION_H
#define GAME_CONFIGURATION_H

class GameConfiguration
{
public:
	GameConfiguration();
	GameConfiguration(int fieldWidth, int fieldHeight, int boxWidthPct, int boxHeighPct);

	int fieldWidth() const;
	int fieldHeight() const;

	int boxWidthPct() const;
	int boxHeightPct() const;

private:
	void setDefaults();

	int _fieldWidthDefault;
	int _fieldHeightDefault;
	int _boxWidthPctDefault;
	int _boxHeightPctDefault;

	int _fieldWidth;
	int _fieldHeight;
	int _boxWidthPct;
	int _boxHeightPct;
};

#endif
