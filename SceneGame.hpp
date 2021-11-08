#ifndef SceneGame_hpp
#define SceneGame_hpp
#include "Scene.hpp"
#include "Input.hpp"
#include "Object.hpp"
#include "C_Sprite.hpp"
#include "C_KeyboardMovement.hpp"
#include "WorkingDirectory.hpp"
#include "ResourceAllocator.hpp"

class SceneGame : public Scene
{
public:
    SceneGame(WorkingDirectory& workingDir, ResourceAllocator<sf::Texture>& textureAllocator);
    void onCreate() override;
    void onDestroy() override;
    void processInput() override;
    void update(float deltaTime) override;
    void lateUpdate(float deltaTime) override;
    void draw(Window& window) override;
private:
    ResourceAllocator<sf::Texture>& textureAllocator;
    std::shared_ptr<Object> player;
    WorkingDirectory& workingDir;
    Input input;
};
#endif