#include "Brick.h"


Brick::Brick(Game GameInstance, int iLength, int iHeigth, int x, int y, int life) : GameObject(GameInstance, iLength, iHeigth, x, y)
{
	nbLife = life;
}

int Brick::getNbLife()
{
	return nbLife;
}


void Brick::loseLife()
{
	nbLife = nbLife - 1;
}