#ifndef C_Animation_hpp
#define C_Animation_hpp

#include "Component.hpp"
#include "Animation.hpp"
#include "C_Sprite.hpp"

enum class AnimationState
{
    None,
    Idle,
    Walk
};

class C_Animation : public Component
{
public:
    C_Animation(Object* owner);
    void awake() override;
    void update(float deltaTime) override;
    void addAnimation(AnimationState state, std::shared_ptr<Animation> animation);
    void setAnimationState(AnimationState state);
    const AnimationState& getAnimationState() const;
    void setAnimationDirection(FacingDirection dir);
private:
    std::shared_ptr<C_Sprite> sprite;
    std::map<AnimationState, std::shared_ptr<Animation>> animations;
    std::pair<AnimationState, std::shared_ptr<Animation>> curAnimation;
};

#endif