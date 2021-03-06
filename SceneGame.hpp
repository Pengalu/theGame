#ifndef SceneGame_hpp
#define SceneGame_hpp

#include "C_Animation.hpp"
#include "Scene.hpp"
#include "Input.hpp"
#include "WorkingDirectory.hpp"
#include "Object.hpp"
#include "C_Sprite.hpp"
#include "C_KeyboardMovement.hpp"
#include "ResourceAllocator.hpp"
#include "ObjectCollection.hpp"

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
    WorkingDirectory& workingDir;
    Input input;
    ResourceAllocator<sf::Texture>& textureAllocator;
    ObjectCollection objects;
};
#endif