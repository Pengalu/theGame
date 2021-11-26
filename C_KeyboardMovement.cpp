#include "C_KeyboardMovement.hpp"
#include "Object.hpp"

C_KeyboardMovement::C_KeyboardMovement(Object* owner)
: Component(owner), moveSpeed(200) {}

void C_KeyboardMovement::setInput(Input* input)
{
    this->input = input;
}

void C_KeyboardMovement::setMovementSpeed(int moveSpeed)
{
    this->moveSpeed = moveSpeed;
}

void C_KeyboardMovement::update(float deltaTime)
{
    if (input == nullptr)
    {
        return;
    }
    int xMove = 0;
    if (input->isKeyPressed(Input::Key::Left))
    {
        xMove = -moveSpeed;
        animation->setAnimationDirection(FacingDirection::Left);
    }
    else if (input->isKeyPressed(Input::Key::Right))
    {
        xMove = moveSpeed;
        animation->setAnimationDirection(FacingDirection::Right);
    }
    int yMove = 0;
    if (input->isKeyPressed(Input::Key::Up))
    {
        yMove = -moveSpeed;
    }
    else if (input->isKeyPressed(Input::Key::Down))
    {
        yMove = moveSpeed;
    }
    float xFrameMove = xMove * deltaTime;
    float yFrameMove = yMove * deltaTime;
    owner->transform->addPosition(xFrameMove, yFrameMove);

    if (xFrameMove == 0 && yFrameMove == 0)
    {
        animation->setAnimationState(AnimationState::Idle);
    }
    else
    {
        animation->setAnimationState(AnimationState::Walk);
    }
}

void C_KeyboardMovement::awake()
{
    animation = owner->getComponent<C_Animation>();
}