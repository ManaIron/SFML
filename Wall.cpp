#include "Wall.h"



void Wall::createWalls(Game GameInstance)
{
	wall1 = GameObject(GameInstance, 10, GameInstance.getHeightScreen(), -5, GameInstance.getHeightScreen() / 2);
	wall2 = GameObject(GameInstance, GameInstance.getLengthScreen(),10, GameInstance.getLengthScreen() / 2, -5);
	wall3 = GameObject(GameInstance, 10, GameInstance.getHeightScreen(), GameInstance.getLengthScreen() + 5, GameInstance.getHeightScreen() / 2);
	wall4 = GameObject(GameInstance, GameInstance.getLengthScreen(), 10, GameInstance.getLengthScreen() / 2, GameInstance.getHeightScreen() + 5);

}

