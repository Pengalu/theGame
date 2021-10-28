#include "Engine.h"

void Engine::input()
{
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        window.close();
    }
    player.handleInput();
}