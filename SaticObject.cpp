#include "StaticObject.h"



void StaticObject::createWalls(Game GameInstance)
{
	wall1 = GameObject(GameInstance, 10, GameInstance.getHeightScreen(), -5, GameInstance.getHeightScreen() / 2);
	wall2 = GameObject(GameInstance, GameInstance.getLengthScreen(),10, GameInstance.getLengthScreen() / 2, -5);
	wall3 = GameObject(GameInstance, 10, GameInstance.getHeightScreen(), GameInstance.getLengthScreen() + 5, GameInstance.getHeightScreen() / 2);
	wall4 = GameObject(GameInstance, GameInstance.getLengthScreen(), 10, GameInstance.getLengthScreen() / 2, GameInstance.getHeightScreen() + 5);
}


void StaticObject::createGrid(Game GameInstance)
{
	int sizeX = 15;
	int sizeY = 5;
	int ecart = 10;
	int lengthBrick = (GameInstance.getLengthScreen() - (ecart*(sizeX+1)))/sizeX;
	int heightBrick = ((GameInstance.getHeightScreen()/4)/sizeY) - ecart;
	grid.resize(sizeX, std::vector<Brick>(sizeY));

	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			if (i !=  3 and i != 11)
			{
				grid[i][j] = Brick(GameInstance, lengthBrick, heightBrick, i * (lengthBrick + ecart) + (lengthBrick / 2 + ecart), j * (heightBrick + 10) + 20, 2);
			}
		}
	}
}


