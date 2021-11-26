#include "C_Sprite.hpp"
#include "Object.hpp"

C_Sprite::C_Sprite(Object* owner)
: Component(owner), curTextureID(-1) {}

void C_Sprite::setTextureAllocator(ResourceAllocator<sf::Texture>* allocator)
{
    this->allocator = allocator;
}

void C_Sprite::load(int id)
{
    if (id >= 0 && id != curTextureID)
    {
        curTextureID = id;
        std::shared_ptr<sf::Texture> texture = allocator->get(id);
        sprite.setTexture(*texture);
    }
}


void C_Sprite::load(const std::string& filePath)
{
    if (allocator)
    {
        int textureID = allocator->add(filePath);
        if (textureID >= 0 && textureID != curTextureID)
        {
            curTextureID = textureID;
            std::shared_ptr<sf::Texture> texture = allocator->get(textureID);
            sprite.setTexture(*texture);
        }
    }
}

void C_Sprite::setTextureRect(int x, int y, int width, int height)
{
    sprite.setTextureRect(sf::IntRect(x, y, width, height));
}

void C_Sprite::setTextureRect(const sf::IntRect& rect)
{
    sprite.setTextureRect(rect);
}

void C_Sprite::draw(Window& window)
{
    window.draw(sprite);
}

void C_Sprite::lateUpdate(float deltaTime)
{
    sprite.setPosition(owner->transform->getPosition());
}