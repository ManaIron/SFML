#include "Game.h"


//constructor

Game::Game(int iLengthScreen, int iHeightScreen)
{
	lengthScreen = iLengthScreen;
	heightScreen = iHeightScreen;
}

Game::Game()
{

}

// Gets


int Game::getLengthScreen()
{
	return lengthScreen;
}

int Game::getHeightScreen()
{
	return heightScreen;
}