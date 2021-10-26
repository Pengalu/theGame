#include "Base.h"

BaseObject::BaseObject()
{
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
}
Vector2f BaseObject::getSize()
{
    return size;
}