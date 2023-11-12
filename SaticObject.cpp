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
	int lengthBrick = 40;
	int heightBrick = 20;
	int ecart = (GameInstance.getLengthScreen() - (lengthBrick*sizeX))/ (sizeX+1);
	grid.resize(sizeX, std::vector<Brick>(sizeY));

	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			grid[i][j] = Brick(GameInstance, lengthBrick, heightBrick, i*(lengthBrick+ecart)+(lengthBrick/2 +ecart), j * (heightBrick + 10) + 20, 1);
		}
	}
}


