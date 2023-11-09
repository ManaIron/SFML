#pragma once

#include "GameObject.h"
#include "Game.h"

class Wall : public GameObject
{
public:

	void createWalls(Game GameInstance);

	GameObject wall1;
	GameObject wall2;
	GameObject wall3;
	GameObject wall4;

private:


};