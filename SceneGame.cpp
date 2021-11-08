#include "SceneGame.hpp"

SceneGame::SceneGame(WorkingDirectory& workingDir, ResourceAllocator<sf::Texture>& ResourceAllocator    )
: workingDir(workingDir), textureAllocator(textureAllocator) {}

void SceneGame::onCreate()
{
    player = std::make_shared<Object>();
    auto sprite = player->addComponent<C_Sprite>();
    sprite->setTextureAllocator(&textureAllocator);
    sprite->load(workingDir.get() + "Assets/TF2.png");
    auto movement = player->addComponent<C_KeyboardMovement>();
    movement->setInput(&input);
}

void SceneGame::onDestroy() {}

void SceneGame::processInput()
{
    input.update();
}

void SceneGame::update(float deltaTime)
{
    player->update(deltaTime);
}

void SceneGame::lateUpdate(float deltaTime)
{
    player->lateUpdate(deltaTime);
}

void SceneGame::draw(Window& window)
{
    player->draw(window);
}