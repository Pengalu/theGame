#ifndef Component_hpp
#define Component_hpp
#include "Window.hpp"

class Object;
class Component
{
public:
    Component(Object* owner) : owner(owner) {}
    virtual void awake() {};
    virtual void start() {};
    virtual void update(float deltaTime) {};
    virtual void lateUpdate(float deltaTime) {};
    virtual void draw(Window& window) {};
protected:
    Object* owner;
};

#endif