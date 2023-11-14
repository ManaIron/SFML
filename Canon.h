#pragma once

#include "GameObject.h"
#include "Ball.h"

class Canon : public GameObject
{
public:
	Canon(Game GameInstance, int iLength, int iHeigth, int x, int y);

	float calculAngle(int mousePositionX, int mousePositionY);
private:

};