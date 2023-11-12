#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Game.h"
#include "StaticObject.h"
#include "Brick.h"

#include <iostream>



int main()
{
    Game GameInstance(800, 800);
    sf::RenderWindow window(sf::VideoMode(GameInstance.getLengthScreen(), GameInstance.getHeightScreen()), "Break them all");

    GameObject rect = GameObject(GameInstance, 100, 50, GameInstance.getLengthScreen() / 2, GameInstance.getHeightScreen()-10); //canon
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
        if (event.type != sf::Event::MouseButtonPressed)
        {
            lock_click = false;
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left && lock_click != true)
            {
                ball = Ball(GameInstance, 10, GameInstance.getLengthScreen() / 2, GameInstance.getHeightScreen()-10);
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


            if (ball.collide(statics.wall1.form) == true)
            {
                if (ball.detectXCollide(statics.wall1.form))
                {
                    ball.reboundX();
                    //Change direction;
                }
                else
                {
                    ball.reboundY();
                }
            }
            if (ball.collide(statics.wall2.form) == true)
            {
                if (ball.detectXCollide(statics.wall2.form))
                {
                    ball.reboundX();
                    //Change direction;
                }
                else
                {
                    ball.reboundY();
                }
            }
            if (ball.collide(statics.wall3.form) == true)
            {
                if (ball.detectXCollide(statics.wall3.form))
                {
                    ball.reboundX();
                    //Change direction;
                }
                else
                {
                    ball.reboundY();
                }
            }
            if (ball.collide(statics.wall4.form) == true)
            {
                checkMove = false;
                ball.form->setPosition(GameInstance.getLengthScreen() / 2, GameInstance.getHeightScreen() - 10);

            }
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                
                    if (ball.collide(statics.grid[i][j].form) == true)
                    {
                        if (ball.detectXCollide(statics.grid[i][j].form))
                        {
                            ball.reboundX();
                            //Change direction;
                        }
                        else
                        {
                            ball.reboundY();
                        }
                        statics.grid[i][j].loseLife();
                    }
                    if (statics.grid[i][j].getNbLife() == 0)
                    {
                        statics.grid[i][j].form->setPosition(-100, -100);
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
                window.draw(*statics.grid[i][j].form);
            }
        }

        window.display();

        deltaTime = clock.restart().asSeconds();

    }
    
    return 0;
}