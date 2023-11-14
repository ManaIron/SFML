#include "Canon.h"


Canon::Canon(Game GameInstance, int iLength, int iHeigth, int x, int y) : GameObject(GameInstance, iLength, iHeigth, x, y)
{
}


float Canon::calculAngle(int mousePositionX, int mousePositionY)
{

	float adjSide = mousePositionX - getPosition()[0];
	float oppSide = mousePositionY - getPosition()[1];

	float angle = atan(oppSide / adjSide) * 180 / 3.14;
	return angle;
}