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


//void Ball::reboundBrick(std::vector<std::vector<Brick>> grid)
//{
//    bool hasCollided = false;
//
//    int sizeX = 15;
//    int sizeY = 5;
//
//    grid.resize(sizeX, std::vector<Brick>(sizeY));
//
//    for (int j = 0; j < 5; j++)
//    {
//        for (int i = 0; i < 15; i++)
//        {
//            if (i != 3 and i != 11)
//            {
//                if (collide(grid[i][j].form) == true)
//                {
//                    if (detectXCollide(grid[i][j].form) and !hasCollided)
//                    {
//                        reboundX();
//                        //Change direction;
//                    }
//                    else if (!hasCollided)
//                    {
//                        reboundY();
//                    }
//
//                    hasCollided = true;
//                    grid[i][j].loseLife();
//                    grid[i][j].changeColor();
//                }
//                if (grid[i][j].getNbLife() <= 0)
//                {
//                    grid[i][j].form->setPosition(-100, -100);
//                }
//            }
//        }
//    }
//}