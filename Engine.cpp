#include "Engine.h"

Engine::Engine()
{
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    window.create(VideoMode (resolution.x, resolution.y), "Simple", Style::Fullscreen);
    backgroundTexture.loadFromFile("bg.png");
    backgroundSprite.setTexture(backgroundTexture);
}

void Engine::start()
{
    Clock m_clock;
    while (window.isOpen())
    {
        Time dt = m_clock.restart();
        float dtAsSeconds = dt.asSeconds();
        input();
        update(dtAsSeconds);
        draw();
    }
}