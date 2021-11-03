#ifndef Game_hpp
#define Game_hpp
#include "Window.hpp"
#include "WorkingDirectory.hpp"

class Engine
{
public:
    Engine();
    void update();
    void draw();
    bool isRunning() const;
    void calculateDelta();
private:
    Window window;
    WorkingDirectory workingDir;
    sf::Texture TF2texture;
    sf::Sprite TF2Sprite;
    sf::Clock clock;
    float delta;
};


#endif