#include "Input.hpp"


void Input::update() 
{
    lastFrameKeys.setMask(thisFrameKeys);
    thisFrameKeys.setBit((int)Key::Left, 
        sf::Keyboard::isKeyPressed(sf::Keyboard::A));
    thisFrameKeys.setBit((int)Key::Right, 
        sf::Keyboard::isKeyPressed(sf::Keyboard::D));
    thisFrameKeys.setBit((int)Key::Up, 
        sf::Keyboard::isKeyPressed(sf::Keyboard::W));
    thisFrameKeys.setBit((int)Key::Down, 
        sf::Keyboard::isKeyPressed(sf::Keyboard::S));
    thisFrameKeys.setBit((int)Key::Escape, 
        sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
}



bool Input::isKeyPressed(Key keyCode)
{
    return thisFrameKeys.getBit((int)keyCode);
}

bool Input::isKeyDown(Key keyCode)
{
    return thisFrameKeys.getBit((int)keyCode) && !lastFrameKeys.getBit((int)keyCode);
}

bool Input::isKeyUp(Key keyCode)
{
    return !thisFrameKeys.getBit((int)keyCode) && lastFrameKeys.getBit((int)keyCode);
}
