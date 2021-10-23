#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;

class Player
{
private:
    Vector2f resolution;
    Vector2f position;
    Vector2f velocity;
    Sprite sprite;
    Texture texture;
    bool aPressed;
    bool dPressed;
    bool wPressed;
    bool sPressed;
    bool onGround;
    float xSpeed;
    float ySpeed;
    float weight;
public:
    Player();
    Sprite getSprite();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void stopUp();
    void stopDown();
    void stopLeft();
    void stopRight();
    void update(float elapsedTime);
};