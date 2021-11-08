#include "Engine.hpp"

Engine::Engine()
: window("pisser shitter B))))")
{
    std::shared_ptr<SceneSplashScreen> splashScreen = std::make_shared<SceneSplashScreen>(workingDir, sceneStateMachine, window);
    std::shared_ptr<SceneGame> gameScene = std::make_shared<SceneGame>(workingDir);
    unsigned int splashScreenID = sceneStateMachine.Add(splashScreen);
    unsigned int gameSceneID = sceneStateMachine.Add(gameScene);
    splashScreen->setSwitchtoScene(gameSceneID);
    sceneStateMachine.switchTo(splashScreenID);
    delta = clock.restart().asSeconds();
}

void Engine::updateInput()
{
    sceneStateMachine.processInput();
}

void Engine::update()
{
    window.update();
    sceneStateMachine.update(delta);
}

void Engine::lateUpdate()
{
    sceneStateMachine.lateUpdate(delta);
}

void Engine::draw()
{
    window.beginDraw();
    sceneStateMachine.draw(window);
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