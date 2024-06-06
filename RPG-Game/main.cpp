#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
//-------------------------- INIT ------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game", sf::Style::Default, settings);

//--------------------------- LOAD ------------------------
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if (playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
    {
        std::cout << "Player loaded:" << std::endl;
        playerSprite.setTexture(playerTexture);
        int Xindex = 0;
        int Yindex = 0;
        playerSprite.setTextureRect(sf::IntRect(Xindex*64,Yindex*64,64,64));
        playerSprite.scale(sf::Vector2f(2, 2));
    }
    else
    {
        std::cout << "Player FAIL to loaded:" << std::endl;
    }

//-------------------------- main loop ------------------------
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
//-------------------------- update ---------------------------            
            if (event.type == sf::Event::Closed)
                window.close();
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                window.close();
            
        }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                    sf::Vector2f position = playerSprite.getPosition();
                    playerSprite.setPosition(position + sf::Vector2f(1, 0));
                    int Xindex = 0;
                    int Yindex = 3;
                    playerSprite.setTextureRect(sf::IntRect(Xindex * 64, Yindex * 64, 64, 64));
            }


//------------------------ draw -------------------------------------------
        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        window.display();
    }

    return 0;
}