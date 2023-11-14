#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Game.h"
#include "StaticObject.h"
#include "Brick.h"
#include "Canon.h"

#include <iostream>



int main()
{   
    Game GameInstance(1950, 1080);
    sf::RenderWindow window(sf::VideoMode(GameInstance.getLengthScreen(), GameInstance.getHeightScreen()), "Break them all");

    Canon rect = Canon(GameInstance, GameInstance.getLengthScreen()/10, GameInstance.getHeightScreen()/20, GameInstance.getLengthScreen() / 2, GameInstance.getHeightScreen() - 50); //canon
    StaticObject statics;
    Ball ball;

    statics.createWalls(GameInstance);
    statics.createGrid(GameInstance);

    sf::Clock clock;
    float deltaTime = 0;

    while (window.isOpen())
    {
        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        //std::cout << localPosition.x << "et" << localPosition.y << std::endl;
        //std::cout << rect.calculAngle(localPosition.x, localPosition.y) << std::endl;
        rect.rotate(rect.calculAngle(localPosition.x, localPosition.y));
        

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        static bool lock_click;
        static bool checkClick;
        static bool checkMove = true;

        // Pendant le clique de la souris
        if (event.type != sf::Event::MouseButtonPressed and !checkMove)
        {
            lock_click = false;
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left && lock_click != true)
            {
                ball = Ball(GameInstance, GameInstance.getHeightScreen()/60, GameInstance.getLengthScreen() / 2, GameInstance.getHeightScreen()-50);
                ball.directionVector(localPosition.x, localPosition.y);

                std::cout << "LETS GOO le cliiicck" << std::endl;
                lock_click = true;
                checkClick = true;
                checkMove = true;
            }
        }
        
        window.clear();
        

        if (checkClick)
        {
            if (checkMove)
            {
                ball.move(deltaTime);
            }

            ball.reboundWall(statics.wall1, statics.wall2, statics.wall3);
            
            if (ball.collide(statics.wall4.form) == true)
            {
                checkMove = false;
                ball.form->setPosition(GameInstance.getLengthScreen() / 2, GameInstance.getHeightScreen() - 50);

            }

            //ball.reboundBrick(statics.grid);

            bool hasCollided = false;

            for (int j = 0; j < 5; j++)
            {
                for (int i = 0; i < 15; i++)
                {
                    if (i != 3 and i != 11)
                    {
                        if (ball.collide(statics.grid[i][j].form) == true)
                        {   
                            if (ball.detectXCollide(statics.grid[i][j].form) and !hasCollided)
                            {
                                ball.reboundX();
                                //Change direction;
                            }
                            else if (!hasCollided)
                            {
                                ball.reboundY();
                            }

                            hasCollided = true;
                            statics.grid[i][j].loseLife();
                            statics.grid[i][j].changeColor();
                            //break;
                        }
                        if (statics.grid[i][j].getNbLife() <= 0)
                        {
                            statics.grid[i][j].form->setPosition(-100, -100);
                        }
                    }
                }
            }

            window.draw(*ball.form);
        }


        window.draw(*rect.form);
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (i != 3 and i != 11)
                {
                    window.draw(*statics.grid[i][j].form);
                }
            }
        }

        window.display();
        deltaTime = clock.restart().asSeconds();

    }
    
    return 0;
}