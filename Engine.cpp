#include "Engine.hpp"

Engine::Engine()
: window("pisser shitter B))))")
{
    TF2texture.loadFromFile(workingDir.get() + "Assets/TF2.png");
    TF2Sprite.setTexture(TF2texture);
    delta = clock.restart().asSeconds();
}

void Engine::update()
{
    window.update();
    const sf::Vector2f& spritePos = TF2Sprite.getPosition();
    const int pixelsMoving = 100;
    float frameMovement = pixelsMoving * delta;
    TF2Sprite.setPosition(spritePos.x + frameMovement, spritePos.y);
}


void Engine::draw()
{
    window.beginDraw();
    window.draw(TF2Sprite);
    window.endDraw();
}

bool Engine::isRunning() const
{
    return window.isOpen();
}

void Engine::calculateDelta()
{
    delta = clock.restart().asSeconds();
}