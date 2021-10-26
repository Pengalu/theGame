#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class BaseObject
{
private:
    Vector2f resolution;
    Vector2f size;
public:
    BaseObject();
    Vector2f getSize();
};