#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace sf;

class Engine
{
private:
    RenderWindow window;
    Sprite backgroundSprite;
    Texture backgroundTexture;
    Player player;
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