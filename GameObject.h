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
	GameObject();
	~GameObject(); //destructeur

	int getSizeX();
	int getSizeY();
	std::vector<float> getPosition();
	std::vector<float> getDirection();

	void rotate(int iAngle);
	void move(float deltaTime);
	bool collide(sf::Shape* sForm1);

	sf::Shape* form; //Definit une adresse

	float calculAngle(int mousePositionX, int mousePositionY);
	void directionVector(int mousePositionX, int mousePositionY);
	void reboundX();
	void reboundY();
	bool detectXCollide(sf::Shape* sForm1);

private:

	Game gameAttribut;

	std::vector<float> position;
	std::vector<float> direction;
	std::vector<float> originDirection;
	int sizeX;
	int sizeY;

	//tools

};