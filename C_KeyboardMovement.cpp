#include "C_KeyboardMovement.hpp"
#include "Object.hpp"

C_KeyboardMovement::C_KeyboardMovement(Object* owner)
: Component(owner), moveSpeed(100) {}

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
    }
    else if (input->isKeyPressed(Input::Key::Right))
    {
        xMove = moveSpeed;
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
}