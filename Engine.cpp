#include "Engine.hpp"

Engine::Engine()
: window("pisser shitter B))))")
{
    TF2texture.loadFromFile(workingDir.get() + "Assets/TF2.png");
    TF2Sprite.setTexture(TF2texture);
    delta = clock.restart().asSeconds();
}

void Engine::updateInput() { input.update(); }

void Engine::update()
{
    window.update();
    const sf::Vector2f& spritePos = TF2Sprite.getPosition();
    const int moveSpeed = 100;
    int xMove = 0;
    int yMove = 0;
    if (input.isKeyPressed(Input::Key::Left)) { xMove = -moveSpeed; }
    else if (input.isKeyPressed(Input::Key::Right)) { xMove = moveSpeed; }
    if (input.isKeyPressed(Input::Key::Up)) { yMove = -moveSpeed; }
    else if (input.isKeyPressed(Input::Key::Down)) { yMove = moveSpeed; }
    float yFrameMove = yMove * delta;
    float xFrameMove = xMove * delta;
    TF2Sprite.setPosition(spritePos.x + xFrameMove, spritePos.y + yFrameMove);
    

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