#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class GameObject
{
public: 

	GameObject(int radius); //constructeur de cercle
	GameObject(int length, int heigth);//constructeur de rect
	~GameObject(); //destructeur


private:

	std::vector<int> position;
	int sizeX;
	int sizeY;

	sf::Shape form;

};