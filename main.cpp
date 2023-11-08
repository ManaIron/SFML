#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Game.h"

#include <iostream>
int main()
{


    Game GameInstance(800, 800);
    sf::RenderWindow window(sf::VideoMode(GameInstance.getLengthScreen(), GameInstance.getHeightScreen()), "Break them all");

    GameObject circle = GameObject(GameInstance, 10, GameInstance.getLengthScreen() / 2, GameInstance.getHeightScreen() -10);
    GameObject rect = GameObject(GameInstance, 100, 50, GameInstance.getLengthScreen() / 2, GameInstance.getHeightScreen());
    GameObject brick = GameObject(GameInstance, 75, 30, 500, 100);

    sf::Clock clock;
    float deltaTime = 0;

    while (window.isOpen())
    {
        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        //std::cout << localPosition.x << "et" << localPosition.y << std::endl;
        std::cout << rect.calculAngle(localPosition.x, localPosition.y) << std::endl;
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

        // Pendant le clique de la souris
        if (event.type != sf::Event::MouseButtonPressed)
        {
            lock_click = false;
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left && lock_click != true)
            {

                circle.directionVector(localPosition.x, localPosition.y);

                std::cout << "LETS GOO le cliiicck" << std::endl;
                lock_click = true;
                checkClick = true;
            }
        }


        window.clear();
      
        if (checkClick == true)
        {
            circle.move(deltaTime);
           
            if (circle.collide(circle.form, brick.form) == true)
            {
                brick.form->setFillColor(sf::Color(200, 0,0));
            }
        }

        window.draw(*circle.form);
        window.draw(*rect.form);
        window.draw(*brick.form);

        window.display();

        deltaTime = clock.restart().asSeconds();

    }
    
    return 0;
}