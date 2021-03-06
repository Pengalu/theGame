#include "C_Transform.hpp"

C_Transform::C_Transform(Object* owner)
: Component(owner), position(0.f, 0.f) {}

void C_Transform::setPosition(float x, float y)
{
    position.x = x;
    position.y = y;
}

void C_Transform::setPosition(const sf::Vector2f& pos)
{
    position = pos;
}

void C_Transform::addPosition(float x, float y)
{
    position.x += x;
    position.y += y;
}

void C_Transform::addPosition(sf::Vector2f pos)
{
    position += pos;
}

void C_Transform::setX(float x)
{
    position.x = x;
}

void C_Transform::setY(float y)
{
    position.y = y;
}

void C_Transform::addX(float x)
{
    position.x += x;
}

void C_Transform::addY(float y)
{
    position.y += y;
}

const sf::Vector2f& C_Transform::getPosition() const
{
    return position;
}