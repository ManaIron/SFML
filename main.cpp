
#include "GameObject.h"
#include "Game.h"
#include "StaticObject.h"
#include "Brick.h"
#include "Canon.h"

#include <iostream>


int main()
{
    Game GameInstance(1920, 1080);
    sf::RenderWindow window(sf::VideoMode(GameInstance.getLengthScreen(), GameInstance.getHeightScreen()), "Break them all");

    Canon canonObj = Canon(GameInstance, GameInstance.getLengthScreen() / 10, GameInstance.getHeightScreen() / 10, GameInstance.getLengthScreen() / 2, GameInstance.getHeightScreen()); //canon
    StaticObject statics;

    Ball ball;
    Ball ball1;

    std::vector<Ball> listBall_used;

    statics.createWalls(GameInstance);
    statics.createGrid(GameInstance);

    sf::Clock clock;
    float deltaTime = 0;
    bool end = false;

    sf::Texture texture;
    if (!texture.loadFromFile("arbaletev2.jpg"))
    {
        std::cout << "ERROR:loadTexture" << std::endl;
    }
    texture.loadFromFile("arbaletev2.jpg");

    while (window.isOpen())
    {
        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        canonObj.rotate(canonObj.calculAngle(localPosition.x, localPosition.y));


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        static bool lock_leftClick;
        static bool lock_rightClick;
        static bool checkClick;
        static bool checkMove = true;
        static std::vector<bool> checkMove_right;


        if (event.type != sf::Event::MouseButtonPressed and !checkMove and !statics.checkEndGame())
        {
            lock_leftClick = false;
        }
        if (event.type != sf::Event::MouseButtonPressed and !statics.checkEndGame())
        {
            lock_rightClick = false;
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
            // Left Click de la Souris pour lancer une seule balle (balle par balle)
            if (event.mouseButton.button == sf::Mouse::Left && !lock_leftClick)
            {
                ball = Ball(GameInstance, GameInstance.getHeightScreen() / 60, GameInstance.getLengthScreen() / 2, GameInstance.getHeightScreen());
                ball.form->setFillColor(sf::Color(255, 255, 255));

                ball.directionVector(localPosition.x, localPosition.y);


                lock_leftClick = true;
                checkClick = true;
                checkMove = true;
            }



            // Right Click de la souris qui envoie 5 balles max à la fois 

            /*if (event.mouseButton.button == sf::Mouse::Right && !lock_rightClick)
            {
                ball1 = Ball(GameInstance, GameInstance.getHeightScreen() / 60, GameInstance.getLengthScreen() / 2, GameInstance.getHeightScreen());
                ball1.form->setFillColor(sf::Color(0, 0, 255));

                if (listBall_used.size() < 5)
                {
                    listBall_used.push_back(ball1);
                    checkMove_right.push_back(true);
                    listBall_used[listBall_used.size() - 1].directionVector(localPosition.x, localPosition.y);
                }

                lock_rightClick = true;
                checkClick = true;
            }*/
        }

        static bool lock_space;
        /*if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            lock_space = false;
        }*/
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and !lock_space)
        {
            ball.directionVector(ball.form->getPosition().x, ball.form->getPosition().y);
            for (int i = 0; i < listBall_used.size(); i++)
            {
                listBall_used[i].directionVector(listBall_used[i].form->getPosition().x, listBall_used[i].form->getPosition().y);
            }
            lock_space = true;
        }


        // Start of the gaming tools -----------------------------------------------------

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
                ball.form->setPosition(GameInstance.getLengthScreen() / 2, GameInstance.getHeightScreen());
            }

            if (!ball.hasCollided)
            {
                statics.grid = ball.reboundBrick(statics.grid, statics.grid.size(), statics.grid[0].size());
            }

            window.draw(*ball.form);

            //RIGHT CLICK MOVEMENT -----------------------

            /*for (int i = 0; i < listBall_used.size(); i++)
            {
                listBall_used[i].move(deltaTime);

                listBall_used[i].reboundWall(statics.wall1, statics.wall2, statics.wall3);

                if (listBall_used[i].collide(statics.wall4.form) == true)
                {
                    listBall_used.erase(listBall_used.begin() + i);
                }

                if (!listBall_used[i].hasCollided)
                {
                    statics.grid = listBall_used[i].reboundBrick(statics.grid, statics.grid.size(), statics.grid[0].size());
                }

                window.draw(*listBall_used[i].form);
            }*/
        }

        canonObj.form->setTexture(&texture);
        window.draw(*canonObj.form);

        for (int i = 0; i < statics.grid.size(); i++)
        {
            for (int j = 0; j < statics.grid[0].size(); j++)
            {
                window.draw(*statics.grid[i][j].form);
            }
        }

        window.display();
        deltaTime = clock.restart().asSeconds();

        if (statics.checkEndGame())
        {
            end = true;
            window.close();
            break;
        }
    }

    if (end)
    {
        GameInstance.endGame();
    }

    return 0;

}