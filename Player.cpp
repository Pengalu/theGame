#include "Player.h"

Player::Player()
{
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    xSpeed = 400;
    ySpeed = 400;
    weight = 500;
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
    if (wPressed && velocity.y < 500 && onGround)
    {
        velocity.y += ySpeed * elapsedTime * 50;
        onGround = false;
    }
    if (sPressed && velocity.y > -500)
    {
        velocity.y -= ySpeed * elapsedTime * 5;
    }
    if (dPressed && velocity.x < 500)
    {
        velocity.x += (xSpeed * elapsedTime) * 5;
    }
    if (aPressed && velocity.x > -500)
    {
        velocity.x -= (xSpeed * elapsedTime) * 5;
    }

    // if statements for changing velocities while not moving
    if (!dPressed && !aPressed)
    {
        if (velocity.x < 0)
        {
            velocity.x += abs(velocity.x) * elapsedTime * (xSpeed / 100);
        }
        else
        {
            velocity.x -= velocity.x * elapsedTime * (xSpeed / 100);
        }
    }
    if (!onGround)
    {
        velocity.y -= weight * elapsedTime;
    }
    if (position.y > 1080 - sprite.getGlobalBounds().height)
    {
        position.y = 1080 - sprite.getGlobalBounds().height;
        velocity.y = 0;
        onGround = true;
    }
    position.y -= elapsedTime * velocity.y;
    position.x += elapsedTime * velocity.x;
    sprite.setPosition(position);
}
