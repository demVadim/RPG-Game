#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int main()
{

    //-------------------------- INIT ------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);

    sf::RectangleShape bullet(sf::Vector2f(50, 25));
    
    //--------------------------- LOAD ------------------------
    //--------------------------- SKELETON ------------------------
  
    sf::Texture skeletonTexture;
    sf::Sprite  skeletonSprite;

    if (skeletonTexture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png"))
    {
        std::cout << "Skeleton loaded:" << std::endl;
        skeletonSprite.setTexture(skeletonTexture);
        skeletonSprite.setPosition(sf::Vector2f(400, 100));
        int Xindex = 0;
        int Yindex = 2;
        skeletonSprite.setTextureRect(sf::IntRect(Xindex * 64, Yindex * 64, 64, 64));
        skeletonSprite.scale(sf::Vector2f(3, 3));
    }
    else
    {
        std::cout << "Skeleton FAIL to loaded:" << std::endl;
    }
    //--------------------------- SKELETON ------------------------
  
    //--------------------------- PLAYER --------------------------
    sf::Texture playerTexture;
    sf::Sprite  playerSprite;

    if (playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
    {
        std::cout << "Player loaded:" << std::endl;
        playerSprite.setTexture(playerTexture);
        int Xindex = 0;
        int Yindex = 0;
        playerSprite.setTextureRect(sf::IntRect(Xindex*64,Yindex*64,64,64));
        playerSprite.scale(sf::Vector2f(2, 2));
        playerSprite.setPosition(sf::Vector2f(1650, 800));
    }
    else
    {
        std::cout << "Player FAIL to loaded:" << std::endl;
    }
    //--------------------------- PLAYER --------------------------
    //--------------------------- LOAD ------------------------

    //------------- calculate bullet

    bullet.setPosition(playerSprite.getPosition());

    sf::Vector2f direction = skeletonSprite.getPosition() - bullet.getPosition();

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

        bullet.setPosition(bullet.getPosition() + direction * 0.001f);
        

        sf::Vector2f position = playerSprite.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            playerSprite.setPosition(position + sf::Vector2f(2, 0));
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                playerSprite.setPosition(position + sf::Vector2f(-2, 0));
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                    playerSprite.setPosition(position + sf::Vector2f(0, -2));
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                        playerSprite.setPosition(position + sf::Vector2f(0, 2));

        //------------------------ draw -------------------------------------------
        window.clear(sf::Color::Black);

        window.draw(skeletonSprite);
        window.draw(playerSprite);
        window.draw(bullet);

        window.display();
    }

    return 0;
}