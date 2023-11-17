#include "Game.h"


//constructor

Game::Game(int iLengthScreen, int iHeightScreen)
{
	lengthScreen = iLengthScreen;
	heightScreen = iHeightScreen;
}

Game::Game()
{
}



// Gets


int Game::getLengthScreen()
{
	return lengthScreen;
}

int Game::getHeightScreen()
{
	return heightScreen;
}


//Ending the game


void Game::endGame()
{
    sf::RenderWindow victoryWindow(sf::VideoMode(lengthScreen, heightScreen), "VICTORY");
    sf::Font font;
    sf::Font font2;
    font.loadFromFile("Aiden-v7DO.otf");  // Remplacez "arial.ttf" par le chemin de votre police de caractères
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

    // Centrez le texte dans la fenêtre de victoire
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