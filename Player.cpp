#include "Player.h"

Player::Player()
{
    xSpeed = 400;
    ySpeed = 400;
    weight = 10;
    texture.loadFromFile("tf2.png");
    sprite.setTexture(texture);
    position.x = 500;
    position.y = 800;
    velocity.x = 0;
    velocity.y = 0;
}

Sprite Player::getSprite()
{
    return sprite;
}

void Player::moveUp()
{
    wPressed = true;
}

void Player::moveDown()
{
    sPressed = true;
}
void Player::moveLeft()
{
    aPressed = true;
}

void Player::moveRight()
{
    dPressed = true;
}

void Player::stopUp()
{
    wPressed = false;
}

void Player::stopDown()
{
    sPressed = false;
}

void Player::stopLeft()
{
    aPressed = false;
}

void Player::stopRight()
{
    dPressed = false;
}

void Player::update(float elapsedTime)
{   
    // if statements for jumping, moving right, moving left
    if (wPressed && velocity.y < 500)
    {
        velocity.y += ySpeed * elapsedTime;
    }
    if (dPressed && velocity.x < 500)
    {
        velocity.x += (xSpeed * elapsedTime) * 3;
    }
    if (aPressed && velocity.x > -500)
    {
        velocity.x -= (xSpeed * elapsedTime) * 3;
    }

    // if statements for decreasing velocities while not moving
    if (!dPressed && !aPressed)
    {
        if (velocity.x < 0)
        {
            velocity.x += abs(velocity.x) * elapsedTime * 2;
        }
        else
        {
            velocity.x -= velocity.x * elapsedTime * 2;
        }
    }
    if (!wPressed && !sPressed)
    {

    }   
    if (position.y < 0)
    {
        position.y -= elapsedTime * velocity.y;
    }
    else
    {
        position.y = 0;
        velocity.y = 0;
        onGround = true;
    }
    position.x += elapsedTime * velocity.x;
    sprite.setPosition(position);
}
