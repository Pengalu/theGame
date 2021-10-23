#include "Platform.h"

Platform::Platform()
{
    position.x = 50;
    position.y = 50;
    platShape.setSize(Vector2f(50, 5));
    platShape.setPosition(position);
    platShape.setFillColor(sf::Color::Black);
}

FloatRect Platform::getPosition()
{
    return platShape.getGlobalBounds();
}

RectangleShape Platform::getShape()
{
    return platShape;
}