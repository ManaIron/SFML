#pragma once

#include "GameObject.h"
#include "Brick.h"
#include <iostream>
#include <vector>

class Ball : public GameObject
{
public:
	Ball(Game GameInstance, int iRadius, int x, int y);
	Ball();
	~Ball();

	void reboundWall(GameObject wall1, GameObject wall2, GameObject wall3);
	std::vector<std::vector<Brick>> reboundBrick(std::vector<std::vector<Brick>> grid, int sizeX, int sizeY);
private:

};