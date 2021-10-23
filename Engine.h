#pragma once
#ifdef _WIN32 || _WIN64
#include "SFML\Graphics.hpp"
#elif __linux__ || __unix || __unix__
#include "SFML/Graphics.hpp" 
#endif
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