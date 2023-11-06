#include <SFML/Graphics.hpp>

#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::CircleShape shape(100);
    sf::RectangleShape rect(sf::Vector2f(100, 150));
    sf::RectangleShape rect_rouge(sf::Vector2f(10, 15));
    shape.setFillColor(sf::Color::Green);
    rect.setFillColor(sf::Color::Green);
    rect_rouge.setFillColor(sf::Color::Red);

    //Tests

    rect.setPosition(400, 800);
    rect_rouge.setPosition(300, 300);

    rect.setOrigin(50, 75);
    rect.setRotation(45);

    
    sf::Vector2f a = rect.getPosition();
    std::cout << a.x << "et" << a.y << std::endl;


    // ENd Test

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(rect);
        window.draw(rect_rouge);
        window.display();
    }

    return 0;
}