#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include "Player.h"
#include "Skeleton.h"

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

    Player player;
    Skeleton skeleton;

    player.Initialize();
    skeleton.Initialize();
    
    player.Load();
    skeleton.Load();

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

        
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                    {
                        bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));

                        int i = bullets.size() - 1;
                        bullets[i].setPosition(player.sprite.getPosition());
                    }

                    player.Update();
                    skeleton.Update();

                    for (size_t i = 0; i <bullets.size();i++)
                    {
                        sf::Vector2f bulletDirection = bulletDirection = skeleton.sprite.getPosition() - bullets[i].getPosition();
                        bulletDirection = NormalizeVector(bulletDirection);
                        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
                    }

                    
                    //------------------------update --------------------
                    //------------------------ draw ---------------------
        window.clear(sf::Color::Black);
        skeleton.Draw();
        player.Draw();
        window.draw(skeleton.sprite);
        window.draw(player.sprite);
        
        for (size_t i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }

        window.display();
    }

    return 0;
}