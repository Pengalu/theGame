#ifndef SceneSplashScreen_hpp
#define SceneSplashScreen_hpp
#include <SFML/Graphics.hpp>
#include "WorkingDirectory.hpp"
#include "SceneStateMachine.hpp"
#include "ResourceAllocator.hpp"

class SceneSplashScreen : public Scene
{
public:
    SceneSplashScreen(WorkingDirectory& workingdir, SceneStateMachine& sceneStateMachine, Window& window, ResourceAllocator<sf::Texture>& textureAllocator);
    void onCreate() override;
    void onDestroy() override;
    void onActivate() override;
    void setSwitchtoScene(unsigned int id);
    void update(float deltaTime) override;
    void draw(Window& window) override;
private:
    sf::Texture splashTexture;
    sf::Sprite splashSprite;
    WorkingDirectory& workingdir;
    SceneStateMachine& sceneStateMachine;
    Window& window;
    float showForSeconds;
    float currentSeconds;
    unsigned int switchToState;
    ResourceAllocator<sf::Texture>& textureAllocator;
};


#endif