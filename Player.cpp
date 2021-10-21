#include "Player.h"

Player::Player()
{
    speed = 400;
    texture.loadFromFile("stickman.png");
    sprite.setTexture(texture);
    position.x = 500;
    position.y = 800;
}

Sprite Player::getSprite()
{
    return sprite;
}

void Player::moveLeft()
{
    aPressed = true;
}

void Player::moveRight()
{
    dPressed = true;
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
    if (dPressed)
    {
        position.x += speed * elapsedTime;
    }
    if (aPressed)
    {
        position.x -= speed * elapsedTime;
    }
    sprite.setPosition(position);
}