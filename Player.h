#pragma once
#ifdef _WIN32 || _WIN64
#include "SFML\Graphics.hpp"
#elif __linux__ || __unix || __unix__
#include "SFML/Graphics.hpp" 
#endif
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