#pragma once

#include "GameObject.h"

class Brick : public GameObject
{
public:
	Brick(Game GameInstance, int iLength, int iHeigth, int x, int y, int life);

	int getNbLife();
	void loseLife();

private:

	int nbLife;

};