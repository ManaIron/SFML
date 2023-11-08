#pragma once

#include "Game.h"

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class GameObject
{
public: 

	GameObject(Game GameInstance, int radius, int x, int y); //constructeur de cercle
	GameObject(Game GameInstance, int length, int heigth, int x, int y);//constructeur de rect
	~GameObject(); //destructeur

	int getSizeX();
	int getSizeY();
	std::vector<int> getPosition();

	void rotate(int iAngle);
	void move(float dirX, float dirY, float deltaTime);
	bool collide(sf::Shape* sForm1, sf::Shape* sForm2);

	sf::Shape* form; //Definit une adresse


private:

	Game gameAttribut;
	std::vector<int> position;
	int sizeX;
	int sizeY;

	//tools

	std::vector<float> directionVector(int mousePositionX, int mousePositionY);

};