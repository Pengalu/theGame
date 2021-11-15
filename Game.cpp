#include "Game.hpp"

Game::Game()
: window("pisser shitter B))))")
{
    std::shared_ptr<SceneSplashScreen> splashScreen = std::make_shared<SceneSplashScreen>(workingDir, sceneStateMachine, window, textureAllocator);
    std::shared_ptr<SceneGame> gameScene = std::make_shared<SceneGame>(workingDir, textureAllocator);
    unsigned int splashScreenID = sceneStateMachine.Add(splashScreen);
    unsigned int gameSceneID = sceneStateMachine.Add(gameScene);
    splashScreen->setSwitchtoScene(gameSceneID);
    sceneStateMachine.switchTo(splashScreenID);
    delta = clock.restart().asSeconds();
}

void Game::updateInput()
{
    sceneStateMachine.processInput();
}

void Game::update()
{
    window.update();
    sceneStateMachine.update(delta);
}

void Game::lateUpdate()
{
    sceneStateMachine.lateUpdate(delta);
}

void Game::draw()
{
    window.beginDraw();
    sceneStateMachine.draw(window);
    window.endDraw();
}

bool Game::isRunning() const
{
    return window.isOpen();
}

void Game::calculateDelta()
{
    delta = clock.restart().asSeconds();
}