#ifndef Object_hpp
#define Object_hpp
#include <vector>
#include <memory>
#include "Component.hpp"
#include "Window.hpp"
#include "C_Transform.hpp"
class Object
{
public:
    Object();
    void awake();
    void start();
    void update(float deltaTime);
    void lateUpdate(float deltaTime);
    void draw(Window& window);
    template <typename T> std::shared_ptr<T> addComponent()
    {
        static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");
        for (auto& existingComponent : components)
        {
            if (std::dynamic_pointer_cast<T>(existingComponent))
            {
                return std::dynamic_pointer_cast<T>(existingComponent);
            }
        }
        std::shared_ptr<T> newComponent = std::make_shared<T>(this);
        components.push_back(newComponent);
        return newComponent;
    };
    template <typename T> std::shared_ptr<T> getComponent()
    {
        for (auto& existingComponent : components)
        {
            if (std::dynamic_pointer_cast<T>(existingComponent))
            {
                return std::dynamic_pointer_cast<T>(existingComponent);
            }
        }
        return nullptr;
    };
    std::shared_ptr<C_Transform> transform;
private:
    std::vector<std::shared_ptr<Component>> components;
};

#endif