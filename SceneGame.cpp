#include "SceneGame.hpp"

SceneGame::SceneGame(WorkingDirectory& workingDir, ResourceAllocator<sf::Texture>& textureAllocator)
: workingDir(workingDir), textureAllocator(textureAllocator) {}

void SceneGame::onCreate()
{
    std::shared_ptr<Object> player = std::make_shared<Object>();

    auto sprite = player->addComponent<C_Sprite>();
    sprite->setTextureAllocator(&textureAllocator);

    auto movement = player->addComponent<C_KeyboardMovement>();
    movement->setInput(&input);

    auto animation = player->addComponent<C_Animation>();

    int textureID = textureAllocator.add(workingDir.get() + "Assets/Viking.png");

    const int frameWidth = 165;
    const int frameHeight = 145;

    std::shared_ptr<Animation> idleAnimation = std::make_shared<Animation>(FacingDirection::Right);
    const float idleAnimFrameSeconds = 0.2f;
    idleAnimation->addFrame(textureID, 600, 0, frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->addFrame(textureID, 800, 0, frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->addFrame(textureID, 0, 145, frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->addFrame(textureID, 200, 145, frameWidth, frameHeight, idleAnimFrameSeconds);
    animation->addAnimation(AnimationState::Idle, idleAnimation);

    std::shared_ptr<Animation> walkAnimation = std::make_shared<Animation>(FacingDirection::Right);
    const float walkingAnimFrameSeconds = 0.15f;
    walkAnimation->addFrame(textureID, 600, 290, frameWidth, frameHeight, walkingAnimFrameSeconds);
    walkAnimation->addFrame(textureID, 800, 290, frameWidth, frameHeight, walkingAnimFrameSeconds);
    walkAnimation->addFrame(textureID, 0, 435, frameWidth, frameHeight, walkingAnimFrameSeconds);
    walkAnimation->addFrame(textureID, 200, 435, frameWidth, frameHeight, walkingAnimFrameSeconds);
    walkAnimation->addFrame(textureID, 400, 435, frameWidth, frameHeight, walkingAnimFrameSeconds);
    animation->addAnimation(AnimationState::Walk, walkAnimation);

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
    objects.lateUpdate(deltaTime);
}

void SceneGame::draw(Window& window)
{
    objects.draw(window);
}