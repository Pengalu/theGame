#ifndef Game_hpp
#define Game_hpp
#include "Input.hpp"
#include "Window.hpp"
#include "WorkingDirectory.hpp"

class Engine
{
public:
    Engine();
    void updateInput();
    void update();
    void draw();
    bool isRunning() const;
    void calculateDelta();
private:
    Window window;
    WorkingDirectory workingDir;
    Input input;
    sf::Texture TF2texture;
    sf::Sprite TF2Sprite;
    sf::Clock clock;
    float delta;
};


#endif