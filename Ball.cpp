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


std::vector<std::vector<Brick>> Ball::reboundBrick(std::vector<std::vector<Brick>> grid, int sizeX, int sizeY)
{
    std::vector < std::vector<Brick>> finalGrid;
    bool hasCollided = false;

    finalGrid.resize(sizeX, std::vector<Brick>(sizeY));
    grid.resize(sizeX, std::vector<Brick>(sizeY));

    for (int j = 0; j < sizeY; j++)
    {
        for (int i = 0; i < sizeX; i++)
        {

            if (collide(grid[i][j].form) == true)
            {
                if (detectXCollide(grid[i][j].form) and !hasCollided)
                {
                    reboundX();
                    //Change direction;
                }
                else if (!hasCollided)
                {
                    reboundY();
                }

                hasCollided = true;
                grid[i][j].loseLife();
                grid[i][j].changeColor();
            }
            if (grid[i][j].getNbLife() <= 0)
            {
                grid[i][j].form->setPosition(-100, -100);
            }

        }
    }
    finalGrid = grid;
    return finalGrid;
}