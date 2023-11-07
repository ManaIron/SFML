#include <SFML/Graphics.hpp>
#include "GameObject.h"

#include <iostream>
int main()
{

    //Tests
    //
    //GameObject shape = GameObject(100, 400, 400);
    //sf::RectangleShape rect(sf::Vector2f(100, 150));
    //sf::RectangleShape rect_rouge(sf::Vector2f(10, 15));

    //rect.setFillColor(sf::Color::Green);
    //rect_rouge.setFillColor(sf::Color::Red);

    //rect.setPosition(400, 400);
    //rect_rouge.setPosition(400, 400);
    //rect.setOrigin(50, 75);
    //
    ////shape.rotate(90);
    //
    //sf::Vector2f a = rect.getPosition();
    //std::cout << a.x << "et" << a.y << std::endl;

    // ENd Test

    int lengthScreen = 800;
    int heightScreen = 800;
    sf::RenderWindow window(sf::VideoMode(lengthScreen, heightScreen), "SFML works!");

    GameObject circle = GameObject(100, lengthScreen / 2, heightScreen / 2);

    sf::Clock clock;
    float deltaTime = 0;

while (window.isOpen())
{
    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
    std::cout << localPosition.x << "et" << localPosition.y << std::endl;

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }


    window.clear();
      
    //Test
    //window.draw(rect);
    //window.draw(rect_rouge);
    //End Test


    window.display();

    deltaTime = clock.restart().asSeconds();

}
    

    return 0;
}