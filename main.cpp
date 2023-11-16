#include <SFML/Graphics.hpp>
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
    Ball ball = Ball(GameInstance, GameInstance.getHeightScreen() / 60, GameInstance.getLengthScreen() / 2, GameInstance.getHeightScreen());
    Ball ball1 = Ball(GameInstance, GameInstance.getHeightScreen() / 60, GameInstance.getLengthScreen() / 2, GameInstance.getHeightScreen());

    std::vector<Ball> listBall = {};
    std::vector<Ball> listBall_used = {};

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
                //ball = Ball(GameInstance, GameInstance.getHeightScreen() / 60, GameInstance.getLengthScreen() / 2, GameInstance.getHeightScreen());
                ball.form->setFillColor(sf::Color(255, 255, 255));
                listBall_used = { ball };

                for (int i = 0; i < listBall_used.size(); i++)
                {
                    listBall_used[i].directionVector(localPosition.x, localPosition.y);
                }

                std::cout << "LETS GOO le cliiicck gaughe" << std::endl;
                lock_leftClick = true;
                checkClick = true;
                checkMove = true;
            }

            // Right Click de la souris qui envoie 10 balles max � la fois 

            if (event.mouseButton.button == sf::Mouse::Right && !lock_rightClick)
            {
                
                ball1.form->setFillColor(sf::Color(0, 0, 255));

                listBall_used = { ball1, ball1, ball1, ball1, ball1 };

                /*for (int i = 0; i < listBall.size(); i++)
                {
                    if (listBall[i].form->getPosition().x == GameInstance.getLengthScreen() / 2 and listBall[i].form->getPosition().y == GameInstance.getHeightScreen())
                    {
                        for (int j = i; j >= 0; j--)
                        {
                            listBall_used = {listBall[i-j]};
                        }
                        break;
                    }
                }*/


                for (int j = 0; j < listBall_used.size(); j++)
                {
                    listBall_used[j].directionVector(GameInstance.getLengthScreen() / 2, GameInstance.getHeightScreen());
                }

                for (int i = 0; i < listBall_used.size(); i++)
                {
                    if (listBall_used[i].form->getPosition().x == GameInstance.getLengthScreen() / 2 and listBall_used[i].form->getPosition().y == GameInstance.getHeightScreen())
                    {
                        listBall_used[i].directionVector(localPosition.x, localPosition.y);
                        break;
                    }
                }
                

                std::cout << "LETS GOO le cliiicck droit" << std::endl;
                lock_rightClick = true;
                checkClick = true;
                checkMove = true;
            }
        }


        window.clear();


        if (checkClick)
        {
            if (checkMove)
            {
                for (int i = 0; i < listBall_used.size(); i++)
                {
                    listBall_used[i].move(deltaTime);
                }
            }

            for (int i = 0; i < listBall_used.size(); i++)
            {
                listBall_used[i].reboundWall(statics.wall1, statics.wall2, statics.wall3);

                if (listBall_used[i].collide(statics.wall4.form) == true)
                {
                    checkMove = false;
                    listBall_used[i].form->setPosition(GameInstance.getLengthScreen() / 2, GameInstance.getHeightScreen());
                }

                if (!listBall_used[i].hasCollided)
                {
                    statics.grid = listBall_used[i].reboundBrick(statics.grid, statics.grid.size(), statics.grid[0].size());
                }

                window.draw(*listBall_used[i].form);
            }
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
        sf::RenderWindow victoryWindow(sf::VideoMode(1960, 1080), "VICTORY");
        sf::Font font;
        sf::Font font2;
        font.loadFromFile("Aiden-v7DO.otf");  // Remplacez "arial.ttf" par le chemin de votre police de caract�res
        font2.loadFromFile("BALLOON DREAMS.ttf");
        sf::Text victoryText;
        sf::Text ggText;
        victoryText.setFont(font);
        ggText.setFont(font2);
        victoryText.setString("Victory!");
        ggText.setString("GG");
        victoryText.setCharacterSize(100);
        ggText.setCharacterSize(100);
        victoryText.setFillColor(sf::Color::White);
        ggText.setFillColor(sf::Color::White);
        victoryText.setStyle(sf::Text::Bold);
        ggText.setStyle(sf::Text::Bold);

        // Centrez le texte dans la fen�tre de victoire
        victoryText.setPosition((1960 - victoryText.getGlobalBounds().width) / 2, (1080 - victoryText.getGlobalBounds().height) / 2 - 20);
        ggText.setPosition((1960 - ggText.getGlobalBounds().width) / 2, (1080 - ggText.getGlobalBounds().height) / 2 + victoryText.getGlobalBounds().height + 20);

        while (victoryWindow.isOpen())
        {
            sf::Event victoryEvent;
            while (victoryWindow.pollEvent(victoryEvent))
            {
                if (victoryEvent.type == sf::Event::Closed)
                {
                    victoryWindow.close();
                }
            }

            victoryWindow.clear(sf::Color(255, 155, 155));
            victoryWindow.draw(victoryText);
            victoryWindow.draw(ggText);
            victoryWindow.display();
        }
    }

    return 0;

}