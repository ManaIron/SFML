#pragma once

#include "GameObject.h"
#include "Brick.h"
#include <vector>

class Ball : public GameObject
{
public:
	Ball(Game GameInstance, int iRadius, int x, int y);
	Ball();
	~Ball();

	void reboundWall(GameObject wall1, GameObject wall2, GameObject wall3);
	//void reboundBrick(std::vector<std::vector<Brick>> grid);
private:

};