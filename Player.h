#pragma once
#include "Base.h"

class Player : public BaseObject
{
private:
    Vector2f position;
    Vector2f velocity;
    Sprite sprite;
    Texture texture;
    bool leftPressed;
    bool rightPressed;
    bool upPressed;
    bool downPressed;
    float xSpeed;
    float ySpeed;
    float weight;
    enum State
    {
        stateStanding,
        stateRunning,
        stateJumping,
        stateFalling,
        stateDucking
    };
    State state_;
public:
    Player();
    Sprite getSprite();
    void handleInput();
    void update(float elapsedTime);
};