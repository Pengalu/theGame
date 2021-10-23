#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Platform.h"
using namespace sf;

class Engine
{
private:

    RenderWindow window;
    Sprite backgroundSprite;
    Texture backgroundTexture;
    Player player;
    Platform platform;
    bool on_pause;
    // handled by Input.cpp
    void input();
    // handled by Update.cpp
    void update(float dtAsSeconds);
    // handled by Draw.cpp
    void draw();
public:
    // handled by Engine.cpp
    Engine();
    void start();
};