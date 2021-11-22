#include "C_Animation.hpp"
#include "Object.hpp"

C_Animation::C_Animation(Object* owner)
: Component(owner), curAnimation(AnimationState::None, nullptr) {}

void C_Animation::awake()
{
    sprite = owner->getComponent<C_Sprite>();
}

void C_Animation::update(float deltaTime)
{
    if (curAnimation.first != AnimationState::None)
    {
        bool newFrame = curAnimation.second->updateFrame(deltaTime);
        if (newFrame)
        {
            const FrameData* data = curAnimation.second->getCurFrame();
            sprite->load(data->id);
            sprite->setTextureRect(data->x, data->y, data->width, data->height);
        }
    }
}

void C_Animation::addAnimation(AnimationState state, std::shared_ptr<Animation> animation)
{
    auto inserted = animations.insert(std::make_pair(state, animation));
    if (curAnimation.first == AnimationState::None)
    {
        setAnimationState(state);
    }
}

void C_Animation::setAnimationState(AnimationState state)
{
    if (curAnimation.first == state)
    {
        return;
    }
    auto animation = animations.find(state);
    if (animation != animations.end())
    {
        curAnimation.first = animation->first;
        curAnimation.second = animation->second;
        curAnimation.second->reset();
    }
}

const AnimationState& C_Animation::getAnimationState() const
{
    return curAnimation.first;
}