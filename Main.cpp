#include "Engine.hpp"

int main()
{
    Engine engine;
    while (engine.isRunning())
    {
        engine.update();
        engine.draw();
        engine.calculateDelta();
    }
}