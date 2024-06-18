#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

sf::Vector2f NormalizeVector(sf::Vector2f vector)
{
    float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    sf::Vector2f normalizedVector;
    normalizedVector.x = vector.x / magnitude;
    normalizedVector.y = vector.y / magnitude;
    
    return normalizedVector;
}

int main()
{

    //-------------------------- INIT ------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);

    std::vector<sf::RectangleShape>bullets;
    float bulletSpeed = 5.0f;
    

    //--------------------------- LOAD ------------------------
    //--------------------------- SKELETON ------------------------
  
    sf::Texture skeletonTexture;
    sf::Sprite  skeletonSprite;

    if (skeletonTexture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png"))
    {
        std::cout << "Skeleton loaded:" << std::endl;
        skeletonSprite.setTexture(skeletonTexture);
        skeletonSprite.setPosition(sf::Vector2f(1600, 700));
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
        playerSprite.setPosition(sf::Vector2f(0, 0));
    }
    else
    {
        std::cout << "Player FAIL to loaded:" << std::endl;
    }
    //--------------------------- PLAYER --------------------------
    //--------------------------- LOAD ------------------------


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

        
        

        sf::Vector2f position = playerSprite.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            playerSprite.setPosition(position + sf::Vector2f(2, 0));
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                playerSprite.setPosition(position + sf::Vector2f(-2, 0));
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                    playerSprite.setPosition(position + sf::Vector2f(0, -2));
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                        playerSprite.setPosition(position + sf::Vector2f(0, 2));
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                    {
                        bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));

                        int i = bullets.size() - 1;
                        bullets[i].setPosition(playerSprite.getPosition());
                    }

                    for (size_t i = 0; i <bullets.size();i++)
                    {
                        sf::Vector2f bulletDirection = bulletDirection = skeletonSprite.getPosition() - bullets[i].getPosition();
                        bulletDirection = NormalizeVector(bulletDirection);
                        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
                    }
        //------------------------ draw -------------------------------------------
        window.clear(sf::Color::Black);

        window.draw(skeletonSprite);
        window.draw(playerSprite);
        
        for (size_t i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }

        window.display();
    }

    return 0;
}