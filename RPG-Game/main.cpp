#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Skeleton.h"




int main()
{

    //-------------------------- INIT ------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);


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
  
        skeleton.Update();
        player.Update(skeleton);

        //------------------------ draw ---------------------
        window.clear(sf::Color::Black);
        skeleton.Draw(window);
        player.Draw(window);
        window.display();
    }

    return 0;
}