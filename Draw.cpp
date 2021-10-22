#include "Engine.h"

void Engine::draw()
{
    window.clear(Color::White);
    window.draw(backgroundSprite);
    window.draw(player.getSprite());
    window.draw(platform.getShape());
    window.display();
}