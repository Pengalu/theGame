#ifndef Input_hpp
#define Input_hpp
#include <SFML/Graphics.hpp>
#include "Bitmask.hpp"

class Input
{
public:
    enum class Key
    {
        None = 0,
        Left = 1,
        Right = 2,
        Up = 3,
        Down = 4,
        Escape = 5
    };
    void update();
    bool isKeyPressed(Key keyCode);
    bool isKeyDown(Key keyCode);
    bool isKeyUp(Key keyCode);
private:
    Bitmask thisFrameKeys;
    Bitmask lastFrameKeys;
};


#endif