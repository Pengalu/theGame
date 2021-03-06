#ifndef Game_hpp
#define Game_hpp
#include <SFML/Graphics.hpp>
#include "Input.hpp"
#include "Window.hpp"
#include "WorkingDirectory.hpp"
#include "SceneStateMachine.hpp"
#include "SceneSplashScreen.hpp"
#include "SceneGame.hpp"

class Game
{
public:
    Game();
    void updateInput();
    void update();
    void lateUpdate();
    void draw();
    bool isRunning() const;
    void calculateDelta();
private:
    ResourceAllocator<sf::Texture> textureAllocator;
    Window window;
    WorkingDirectory workingDir;
    sf::Clock clock;
    float delta;
    SceneStateMachine sceneStateMachine;
};


#endif