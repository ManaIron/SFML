#include "Brick.h"


Brick::Brick(Game GameInstance, int iLength, int iHeigth, int x, int y, int life) : GameObject(GameInstance, iLength, iHeigth, x, y)
{
	nbLife = life;
}

Brick::Brick() : GameObject()
{
}


int Brick::getNbLife()
{
	return nbLife;
}



void Brick::loseLife()
{
	nbLife = nbLife - 1;
}

void Brick::changeColor()
{
	switch (nbLife)
	{
	case 1:
		form->setFillColor(sf::Color(255,0,0));
		break;
	case 2:
		form->setFillColor(sf::Color(255, 165, 0));
		break;
	case 3:
		form->setFillColor(sf::Color(255,255,0));
		break;
	case 4:
		form->setFillColor(sf::Color(0, 255, 0));
		break;
	}
}