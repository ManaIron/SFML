#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class GameObject
{
public: 

	GameObject(sf::CircleShape cCirlce, int iRay); //constructeur de cercle
	GameObject(sf::RectangleShape rect, int length, int hidth);//constructeur de rect
	~GameObject(); //destructeur


private:

	std::vector<int> position;
	int sizeX;
	int sizeY;

	sf::CircleShape circle;
	sf::RectangleShape rect;

};