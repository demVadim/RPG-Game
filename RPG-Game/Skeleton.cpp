#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize()
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Green);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(64, 64);
}

void Skeleton::Load()
{
    if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png"))
    {
        std::cout << "Skeleton loaded:" << std::endl;
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(1600, 700));
        int Xindex = 0;
        int Yindex = 2;
        sprite.setTextureRect(sf::IntRect(Xindex * size.x, Yindex * size.y, size.y, size.y));
        sprite.scale(sf::Vector2f(3, 3));

        boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
    }
    else
    {
        std::cout << "Skeleton FAIL to loaded:" << std::endl;
    }
}

void Skeleton::Update()
{
    boundingRectangle.setPosition(sprite.getPosition());
}

void Skeleton::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(boundingRectangle);
}
