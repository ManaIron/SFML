#include <iostream>


#include "GameObject.h"


GameObject::GameObject(sf::CircleShape cCircle, int iRay) 
{
	circle = cCircle;
	sizeX = iRay;
	sizeY = iRay;
}

GameObject::GameObject(sf::RectangleShape rRect, int iLength, int iHidth)
{
	rect = rRect;
	sizeX = iLength;
	sizeY = iHidth;
}

GameObject::~GameObject()
{

}


