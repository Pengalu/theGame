#ifndef C_Sprite_hpp
#define C_Sprite_hpp
#include "Component.hpp"
#include "C_Transform.hpp"
#include "ResourceAllocator.hpp"

class C_Sprite : public Component
{
public:
    C_Sprite(Object* owner);
    void setTextureAllocator(ResourceAllocator<sf::Texture>* allocator);
    void load(const std::string& filePath);
    void load(int id);
    void draw(Window& window) override;
    void lateUpdate(float deltaTime) override;
private:
    ResourceAllocator<sf::Texture>* allocator;
    sf::Sprite sprite;
};

#endif