#include "Engine.hpp"

int main()
{
    Engine engine;
    while (engine.isRunning())
    {
        engine.updateInput();
        engine.update();
        engine.draw();
        engine.calculateDelta();
    }
}