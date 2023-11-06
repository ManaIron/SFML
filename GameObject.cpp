#include <iostream>


#include "GameObject.h"


// Constructeurs et Destructeur

GameObject::GameObject(int radius)
{
	form = sf::CircleShape(radius);
	sizeX = 2 * radius;
	sizeY = 2 * radius;
}

GameObject::GameObject(int length, int heigth)
{
	form = sf::RectangleShape(length,heigth);
	sizeX = length;
	sizeY = heigth;
}

GameObject::~GameObject()
{

}


