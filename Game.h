#pragma once

#include <SFML/Graphics.hpp>
#include <vector>


class Game
{
public:
	Game(int iLengthScreen, int iHeightScreen);
	Game(); //constructeur par defaut pour pouvoir le mettre dans GameObject


	int getLengthScreen();
	int getHeightScreen();

	void endGame();

private:

	int lengthScreen;
	int heightScreen;

};