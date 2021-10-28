#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <iterator>Q
#include "Player.h"
using namespace sf;

class Engine
{
private:

    RenderWindow window;
    Sprite backgroundSprite;
    Texture backgroundTexture;
    Player player;
    bool on_pause;
    void collision();
    // input.cpp
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