#include "SceneSplashScreen.hpp"

SceneSplashScreen::SceneSplashScreen(WorkingDirectory& workingdir, SceneStateMachine& sceneStateMachine, Window& window, ResourceAllocator<sf::Texture>& textureAllocator)
: sceneStateMachine(sceneStateMachine), workingdir(workingdir), 
window(window), switchToState(0), currentSeconds(0.f), showForSeconds(3.f), textureAllocator(textureAllocator) {}

void SceneSplashScreen::onCreate()
{
    splashTexture.loadFromFile(workingdir.get() + "Assets/TF2.png");
    splashSprite.setTexture(splashTexture);
    sf::FloatRect spriteSize = splashSprite.getLocalBounds();
    splashSprite.setOrigin(spriteSize.width * 0.5f, spriteSize.height * 0.5f);
    splashSprite.setScale(0.5f, 0.5f);
    sf::Vector2u windowCenter = window.getCenter();
    splashSprite.setPosition(windowCenter.x, windowCenter.y);
}

void SceneSplashScreen::onActivate()
{
    currentSeconds = 0.f;
}

void SceneSplashScreen::onDestroy() {}

void SceneSplashScreen::setSwitchtoScene(unsigned int id)
{
    switchToState = id;
}

void SceneSplashScreen::update(float deltaTime)
{
    currentSeconds += deltaTime;
    if (currentSeconds >= showForSeconds)
    {
        sceneStateMachine.switchTo(switchToState);
    }
}

void SceneSplashScreen::draw(Window& window)
{
    window.draw(splashSprite);
}