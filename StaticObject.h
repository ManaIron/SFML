#pragma once

#include "GameObject.h"
#include "Brick.h"
#include "Ball.h"
#include "Game.h"

class StaticObject: public GameObject
{
public:

	void createWalls(Game GameInstance);
	void createGrid(Game GameInstance);
	bool checkEndGame();

	GameObject wall1;
	GameObject wall2;
	GameObject wall3;
	GameObject wall4;

	std::vector<std::vector<Brick>> grid;

private:



};