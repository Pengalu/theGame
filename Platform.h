#pragma once
#ifdef _WIN32 || _WIN64
#include "SFML\Graphics.hpp"
#elif __linux__ || __unix || __unix__
#include "SFML/Graphics.hpp" 
#endif
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