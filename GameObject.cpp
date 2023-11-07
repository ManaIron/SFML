#include <iostream>


#include "GameObject.h"


// Constructeurs et Destructeur

GameObject::GameObject(int iRadius, int x, int y)
{
	form = new sf::CircleShape(iRadius);
	form->setPosition(x, y);
	sizeX = 2 * iRadius;
	sizeY = 2 * iRadius;
	position = { x , y };
	form->setOrigin(iRadius, iRadius);
}

GameObject::GameObject(int iLength, int iHeigth, int x, int y)
{
	sizeX = iLength;
	sizeY = iHeigth;
	form = new sf::RectangleShape(sf::Vector2f(iLength,iHeigth));
	form->setPosition(x, y);
	position = { x , y };
	form->setOrigin(iLength/2, iHeigth/2);
}

GameObject::~GameObject()
{

}



//Main  Tools


void GameObject::rotate( int iAngle)
{
	form->setRotation(iAngle);
}


bool GameObject::collide(sf::Shape* sForm1, sf::Shape* sForm2)
{

	bool collision = false;
	sf::FloatRect boundingBox = sForm1->getGlobalBounds();
	sf::FloatRect otherBox = sForm2->getGlobalBounds();

	if (boundingBox.intersects(otherBox))
	{
		bool collision = true;
	}
	return collision;
}


void GameObject::move(float dirX,float dirY, float deltaTime)
{
	float speed = deltaTime * 10.f; // 10 pixels par seconde
	position[0] += dirX * speed;
	position[1] += dirY * speed;
}

//Tools


std::vector<float> GameObject::directionVector(int mousePositionX, int mousePositionY)
{

	return { 0,0 };
}