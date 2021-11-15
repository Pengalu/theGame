#include "Game.hpp"

int main()
{
    Game Game;
    while (Game.isRunning())
    {
        Game.updateInput();
        Game.update();
        Game.lateUpdate();
        Game.draw();
        Game.calculateDelta();
    }
}