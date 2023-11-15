#include "StaticObject.h"



void StaticObject::createWalls(Game GameInstance)
{
	wall1 = GameObject(GameInstance, 10, GameInstance.getHeightScreen(), -5, GameInstance.getHeightScreen() / 2);
	wall2 = GameObject(GameInstance, GameInstance.getLengthScreen(),10, GameInstance.getLengthScreen() / 2, -5);
	wall3 = GameObject(GameInstance, 10, GameInstance.getHeightScreen(), GameInstance.getLengthScreen() + 5, GameInstance.getHeightScreen() / 2);
	wall4 = GameObject(GameInstance, GameInstance.getLengthScreen(), 10, GameInstance.getLengthScreen() / 2, GameInstance.getHeightScreen() + 55);
}


void StaticObject::createGrid(Game GameInstance)
{
	int sizeX = 15;
	int sizeY = 5;
	int ecart = 10;
	int lengthBrick = (GameInstance.getLengthScreen() - (ecart*(sizeX+1)))/sizeX;
	int heightBrick = ((GameInstance.getHeightScreen()/4)/sizeY) - ecart;
	grid.resize(sizeX, std::vector<Brick>(sizeY));

	sf::Texture texture;
	if (!texture.loadFromFile("block1.png"))
	{
		std::cout << "ERROR:loadTexture" << std::endl;
	}
	texture.loadFromFile("block1.png");
	
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			if (i !=  3 and i != 11)
			{
				switch (j)
				{
				case 0:
					grid[i][j] = Brick(GameInstance, lengthBrick, heightBrick, i * (lengthBrick + ecart) + (lengthBrick / 2 + ecart), j * (heightBrick + 10) + 150, 1);
					grid[i][j].form->setTexture(&texture);
					break;
				case 1 :
					grid[i][j] = Brick(GameInstance, lengthBrick, heightBrick, i * (lengthBrick + ecart) + (lengthBrick / 2 + ecart), j * (heightBrick + 10) + 150, 2);
					grid[i][j].changeColor();
					break;
				case 2:
					grid[i][j] = Brick(GameInstance, lengthBrick, heightBrick, i * (lengthBrick + ecart) + (lengthBrick / 2 + ecart), j * (heightBrick + 10) + 150, 2);
					grid[i][j].changeColor();
					break;
				case 3:
					grid[i][j] = Brick(GameInstance, lengthBrick, heightBrick, i * (lengthBrick + ecart) + (lengthBrick / 2 + ecart), j * (heightBrick + 10) + 150, 3);
					grid[i][j].changeColor();
					break;
				case 4:
					grid[i][j] = Brick(GameInstance, lengthBrick, heightBrick, i * (lengthBrick + ecart) + (lengthBrick / 2 + ecart), j * (heightBrick + 10) + 150, 4);
					grid[i][j].changeColor();
					break;
				}
			}
			else
			{
				grid[i][j] = Brick(GameInstance, 10, 10, -100, -100, 2);
			}
		}
	}
}


bool StaticObject::checkEndGame()
{
	bool end = true;
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[0].size(); j++)
		{
			if (grid[i][j].form->getPosition().x >= 0 and grid[i][j].form->getPosition().y >= 0)
			{
				end = false;
			}
		}
	}
	return end;
}


