#include <iostream>
#include <cmath>


#include "GameObject.h"


// Constructeurs et Destructeur

GameObject::GameObject(Game GameInstance, int iRadius, int x, int y)
{
	gameAttribut = GameInstance;
	form = new sf::CircleShape(iRadius);
	form->setPosition(x, y);
	sizeX = 2 * iRadius;
	sizeY = 2 * iRadius;
	position = { static_cast<float>(x) , static_cast<float>(y) };
	form->setOrigin(iRadius, iRadius);
	originDirection = { static_cast<float>(gameAttribut.getLengthScreen() / 2), static_cast<float>(gameAttribut.getHeightScreen()) };
}

GameObject::GameObject(Game GameInstance, int iLength, int iHeigth, int x, int y)
{	
	gameAttribut = GameInstance;
	sizeX = iLength;
	sizeY = iHeigth;
	form = new sf::RectangleShape(sf::Vector2f(iLength,iHeigth));
	form->setPosition(x, y);
	position = { static_cast<float>(x) , static_cast<float>(y) };
	form->setOrigin(iLength/2, iHeigth/2);
}

GameObject::GameObject()
{

}


GameObject::~GameObject()
{

}


// Gets

int GameObject::getSizeX()
{
	return sizeX;
}

int GameObject::getSizeY()
{
	return sizeY;
}

std::vector<float> GameObject::getPosition()
{
	return position;
}

std::vector<float> GameObject::getDirection()
{
	return direction;
}

//Main Tools


void GameObject::rotate( int iAngle)
{
	form->setRotation(iAngle);
}


bool GameObject::collide(sf::Shape* sForm1)
{

	bool collision = false;
	sf::FloatRect boundingBox = sForm1->getGlobalBounds();
	sf::FloatRect otherBox = form->getGlobalBounds();


	if (boundingBox.intersects(otherBox))
	{
		collision = true;
	}

	return collision;
}


void GameObject::move(float deltaTime)
{
	float dirX = direction[0];
	float dirY = direction[1];
	float speed = deltaTime * 600.f; // 10 pixels par seconde
	position[0] += dirX * speed;
	position[1] += dirY * speed;

	form->setPosition(position[0], position[1]);
}




//Tools


void GameObject::directionVector(int arrivalX, int arrivalY)
{
	int sizeScreenX = gameAttribut.getLengthScreen();
	int sizeScreenY = gameAttribut.getHeightScreen();

	float dirX = arrivalX - originDirection[0];
	float dirY = arrivalY - originDirection[1];

	float normedDirX = dirX / std::sqrt(dirX * dirX + dirY * dirY);
	float normedDirY = dirY / std::sqrt(dirX * dirX + dirY * dirY);

	direction = { normedDirX, normedDirY };
}


float GameObject::calculAngle(int mousePositionX, int mousePositionY)
{	

	float adjSide = abs(mousePositionX - position[0]);
	float oppSide = abs(mousePositionY - position[1]);

	float angle = atan(oppSide / adjSide) * 180 / 3.14;
	if (mousePositionX > position[0])
	{
		angle = -angle;
	}
	return angle;
}


void GameObject::reboundX()
{	
	direction[1] = -direction[1];
}

void GameObject::reboundY()
{
	direction[0] = -direction[0];
}

bool GameObject::detectXCollide(sf::Shape* sForm1)
{
	sf::FloatRect boundingBox = sForm1->getGlobalBounds();
	sf::FloatRect otherBox = form->getGlobalBounds();
	bool xCollide = false;
	std::cout << abs((abs(position[1] - sForm1->getPosition().y)) - (sizeY / 2 + boundingBox.getSize().y / 2)) << std::endl;
	if (abs((abs(position[1] - sForm1->getPosition().y)) - (sizeY / 2 + boundingBox.getSize().y / 2)) < 0.5)
	{
		xCollide = true;
	}
	return xCollide;
}