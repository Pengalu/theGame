#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;

class Platform
{
private:
    Vector2f position;
    RectangleShape platShape;
public:
    Platform();
    FloatRect getPosition();
    RectangleShape getShape();
};