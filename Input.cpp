#include "Engine.h"

void Engine::input()
{
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        window.close();
    }
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        player.moveLeft();
    }
    else
    {
        player.stopLeft();
    }
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        player.moveRight();
    }
    else
    {
        player.stopRight();
    }
    if (Keyboard::isKeyPressed(Keyboard::W))
    {
        player.moveUp();
    }
    else
    {
        player.stopUp();
    }
}