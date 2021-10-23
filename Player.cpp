#include "Player.h"

Player::Player()
{
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    xSpeed = 400;
    ySpeed = 400;
    weight = 500;
    texture.loadFromFile("gay.png");
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
    }
    if (sPressed && velocity.y > -500)
    {
        velocity.y -= ySpeed * elapsedTime * 5;
    }
    if (dPressed && velocity.x < 500)
    {
        velocity.x += (xSpeed * elapsedTime) * 3;
    }
    if (aPressed && velocity.x > -500)
    {
        velocity.x -= (xSpeed * elapsedTime) * 3;
    }

    // if statements for changing velocities while not moving
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
    if (!onGround)
    {
        velocity.y -= weight * elapsedTime;
    }
    if (position.y < resolution.y - texture.getSize().y)
    {
        position.y -= elapsedTime * velocity.y;
    }
    else if (!onGround && velocity.y < 0)
    {
        position.y = 1080 - texture.getSize().y;
        velocity.y = 0;
        onGround = true;
    }
    position.x += elapsedTime * velocity.x;
    sprite.setPosition(position);
}
