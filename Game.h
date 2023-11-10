#pragma once
#include <vector>


class Game
{
public:
	Game(int iLengthScreen, int iHeightScreen);
	Game(); //constructeur par defaut pour pouvoir le mettre dans GameObject


	int getLengthScreen();
	int getHeightScreen();

private:

	int lengthScreen;
	int heightScreen;

};