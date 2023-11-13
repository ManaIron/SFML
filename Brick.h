#pragma once

#include "GameObject.h"

class Brick : public GameObject
{
public:
	Brick(Game GameInstance, int iLength, int iHeigth, int x, int y, int life);
	Brick();

	int getNbLife();
	void loseLife();
	void changeColor();

private:

	int nbLife;

};