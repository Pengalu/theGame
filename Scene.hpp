#ifndef Scene_hpp
#define Scene_hpp
#include "Window.hpp"

class Scene
{
public:
virtual void onCreate() = 0;
virtual void onDestroy() = 0;
virtual void onActivate() {};
virtual void onDeactivate() {};
virtual void processInput() {};
virtual void update(float deltaTime) {};
virtual void lateUpdate(float deltaTime) {};
virtual void draw(Window& window) {};
};
#endif