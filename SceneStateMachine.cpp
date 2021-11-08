#include "SceneStateMachine.hpp"

SceneStateMachine::SceneStateMachine()
: scenes(0), currentScene(0) {}

void SceneStateMachine::processInput()
{
    if (currentScene)
    {
        currentScene->processInput();
    }
}

void SceneStateMachine::update(float deltaTime)
{
    if (currentScene)
    {
        currentScene->update(deltaTime);
    }
}

void SceneStateMachine::lateUpdate(float deltaTime)
{
    if (currentScene)
    {
        currentScene->lateUpdate(deltaTime);
    }
}

void SceneStateMachine::draw(Window& window)
{
    if (currentScene)
    {
        currentScene->draw(window);
    }
}

unsigned int SceneStateMachine::Add(std::shared_ptr<Scene> scene)
{
    auto inserted = scenes.insert(std::make_pair(insertedSceneID, scene));
    insertedSceneID++;
    inserted.first->second->onCreate();
    return insertedSceneID - 1;
}

void SceneStateMachine::remove(unsigned int id)
{
    auto it = scenes.find(id);
    if (it != scenes.end())
    {
        if (currentScene == it->second)
        {
            currentScene = nullptr;
        }
        it->second->onDestroy();
        scenes.erase(it);
    }
}

void SceneStateMachine::switchTo(unsigned int id)
{
    auto it = scenes.find(id);
    if (it != scenes.end())
    {
        if (currentScene)
        {
            currentScene->onDeactivate();
        }
        currentScene = it->second;
        currentScene->onActivate();
    }
}