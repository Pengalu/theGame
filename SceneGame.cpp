#include "SceneGame.hpp"

SceneGame::SceneGame(WorkingDirectory& workingDir, ResourceAllocator<sf::Texture>& textureAllocator)
: workingDir(workingDir), textureAllocator(textureAllocator) {}

void SceneGame::onCreate()
{
    std::shared_ptr<Object> player = std::make_shared<Object>();
    auto sprite = player->addComponent<C_Sprite>();
    sprite->setTextureAllocator(&textureAllocator);
    sprite->load(workingDir.get() + "Assets/TF2.png");
    auto movement = player->addComponent<C_KeyboardMovement>();
    movement->setInput(&input);
    objects.add(player);
}

void SceneGame::onDestroy() {}

void SceneGame::processInput()
{
    input.update();
}

void SceneGame::update(float deltaTime)
{
    objects.processRemovals();
    objects.processNewObjects();
    objects.update(deltaTime);
}

void SceneGame::lateUpdate(float deltaTime)
{
    objects.update(deltaTime);
}

void SceneGame::draw(Window& window)
{
    objects.draw(window);
}