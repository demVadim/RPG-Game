#include "Player.h"
#include <iostream>

void Player::Initialize()
{

}

void Player::Load()
{
    if (texture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
    {
        std::cout << "Player loaded:" << std::endl;
        sprite.setTexture(texture);
        int Xindex = 0;
        int Yindex = 0;
        sprite.setTextureRect(sf::IntRect(Xindex * 64, Yindex * 64, 64, 64));
        sprite.scale(sf::Vector2f(2, 2));
        sprite.setPosition(sf::Vector2f(0, 0));
    }
    else
    {
        std::cout << "Player FAIL to loaded:" << std::endl;
    }
}

void Player::Update()
{
    sf::Vector2f position = sprite.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        sprite.setPosition(position + sf::Vector2f(2, 0));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        sprite.setPosition(position + sf::Vector2f(-2, 0));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        sprite.setPosition(position + sf::Vector2f(0, -2));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        sprite.setPosition(position + sf::Vector2f(0, 2));
}

void Player::Draw()
{

}
