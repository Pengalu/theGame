#ifndef SceneStateMachine_hpp
#define SceneStateMachine_hpp
#include <memory>
#include <unordered_map>
#include "Scene.hpp"
#include "Window.hpp"

class SceneStateMachine
{
public:
    SceneStateMachine();
    void processInput();
    void update(float deltaTime);
    void lateUpdate(float deltaTime);
    void draw(Window& window);
    unsigned int Add(std::shared_ptr<Scene> scene);
    void switchTo(unsigned int id);
    void remove(unsigned int id);
private:
    std::unordered_map<unsigned int, std::shared_ptr<Scene>> scenes;
    std::shared_ptr<Scene> currentScene;
    unsigned int insertedSceneID;
};

#endif