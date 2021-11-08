#ifndef C_KeyboardMovement_hpp
#define C_KeyboardMovement_hpp

#include "Component.hpp"
#include "Input.hpp"

class C_KeyboardMovement : public Component
{
public:
    C_KeyboardMovement(Object* owner);
    void setInput(Input* input);
    void setMovementSpeed(int moveSpeed);
    void update(float deltaTime);
private:
    int moveSpeed;
    Input* input;
};


#endif