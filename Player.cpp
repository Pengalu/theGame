#include "Player.h"

Player::Player()
{
    xSpeed = 400;
    ySpeed = 400;
    weight = 500;
    texture.loadFromFile("tf2.png");
    sprite.setTexture(texture);
    position.x = 500;
    position.y = 800;
    velocity.x = 0;
    velocity.y = 0;
    state_ = stateStanding;
}

Sprite Player::getSprite()
{
    return sprite;
}

void Player::handleInput()
{
    if (Keyboard::isKeyPressed(Keyboard::W))
    {
        upPressed = true;
    }
    else
    {
        upPressed = false;
    }
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        leftPressed = true;
    }
    else
    {
        leftPressed = false;
    }
    if (Keyboard::isKeyPressed(Keyboard::S))
    {
        downPressed = true;
    }
    else
    {
        downPressed = false;
    }
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        rightPressed = true;
    }
    else
    {
        rightPressed = false;
    }
}

void Player::update(float elapsedTime)
{
    switch (state_) 
    {
        case (stateStanding):
            if (rightPressed)
            {
                state_ = stateRunning;
                velocity.x += xSpeed * elapsedTime * 7.5;
            }
            if (leftPressed)
            {
                state_ = stateRunning;
                velocity.x -= xSpeed * elapsedTime * 7.5;
            }
/*             if (upPressed)
            {
                state_ = stateJumping;
                velocity.y += ySpeed * 2;
            } */
            if (downPressed)
            {
                state_ = stateDucking;
            }
        case (stateRunning):
            if (velocity.x < 0)
            {
                velocity.x += abs(velocity.x) * elapsedTime * (xSpeed / 100);
            }
            else 
            {
                velocity.x -= velocity.x * elapsedTime * (xSpeed / 100);
            }
            if (rightPressed)
            {
                velocity.x += xSpeed * elapsedTime * 7.5;
            }
            if (leftPressed)
            {
                velocity.x -= xSpeed * elapsedTime * 7.5;
            }
/*             if (upPressed)
            {
                state_ = stateJumping;
                velocity.y += ySpeed * 2;
            } */
            if (velocity.x == 0)
            {
                state_ = stateStanding;
            }
        case (stateJumping):
            if (velocity.y < 0)
            {
                state_ = stateFalling;
            }
            if (velocity.y > 500)
            {
            }
        case (stateFalling):
            break;
        case (stateDucking):
            break;
    }
    position.y -= elapsedTime * velocity.y;
    position.x += elapsedTime * velocity.x;
    sprite.setPosition(position);
}