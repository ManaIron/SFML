#include "Ball.h"


Ball::Ball(Game GameInstance, int iRadius, int x, int y) : GameObject(GameInstance, iRadius, x, y)
{

}

Ball::Ball()
{

}

Ball::~Ball()
{

}




void Ball::reboundWall(GameObject wall1, GameObject wall2, GameObject wall3)
{
    if (collide(wall1.form) == true)
    {
        if (detectXCollide(wall1.form))
        {
            reboundX();
            //Change direction;
        }
        else
        {
            reboundY();
        }
    }
    if (collide(wall2.form) == true)
    {
        if (detectXCollide(wall2.form))
        {
            reboundX();
            //Change direction;
        }
        else
        {
            reboundY();
        }
    }
    if (collide(wall3.form) == true)
    {
        if (detectXCollide(wall3.form))
        {
            reboundX();
            //Change direction;
        }
        else
        {
            reboundY();
        }
    }
}