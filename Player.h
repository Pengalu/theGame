#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Player
{
private:
    Vector2f position;
    Sprite sprite;
    Texture texture;
    bool aPressed;
    bool dPressed;
    float speed;
public:
    Player();
    Sprite getSprite();
    void moveLeft();
    void moveRight();
    void stopLeft();
    void stopRight();
    void update(float elapsedTime);
};