#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game");
    sf::CircleShape shape(50.0f);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(sf::Vector2f(100, 100));
    shape.setOutlineThickness(10);
    shape.setOutlineColor(sf::Color::Green);

    sf::RectangleShape rectangle(sf::Vector2f(100, 50)); 
    rectangle.setPosition(sf::Vector2f(150, 100));
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setOrigin(rectangle.getSize()/2.f);
    rectangle.setRotation(90);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                window.close();
        }

        window.clear(sf::Color::Black);

        window.draw(shape);
        window.draw(rectangle);

        window.display();
    }

    return 0;
}