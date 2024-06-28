#include "Math.h"

sf::Vector2f Math::NormalizeVector(sf::Vector2f vector)
{
    float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    sf::Vector2f normalizedVector;
    normalizedVector.x = vector.x / magnitude;
    normalizedVector.y = vector.y / magnitude;

    return normalizedVector;
}

bool Math::CheckRectCollision(sf::FloatRect rect1, sf::FloatRect rect2)
{
    return false;
}
