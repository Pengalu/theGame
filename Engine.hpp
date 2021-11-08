#ifndef Game_hpp
#define Game_hpp
#include <SFML/Graphics.hpp>
#include "Input.hpp"
#include "Window.hpp"
#include "WorkingDirectory.hpp"
#include "SceneStateMachine.hpp"
#include "SceneSplashScreen.hpp"
#include "SceneGame.hpp"

class Engine
{
public:
    Engine();
    void updateInput();
    void update();
    void lateUpdate();
    void draw();
    bool isRunning() const;
    void calculateDelta();
private:
    Window window;
    WorkingDirectory workingDir;
    sf::Clock clock;
    float delta;
    SceneStateMachine sceneStateMachine;
};


#endif