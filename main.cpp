#include <iostream>


using namespace std;


#include <libraryheaders>

int main()
{
    cout << "Hello World" << endl;
    createWindow(title, width, height);
    createOpenGLContext(settings);

    while (windowOpen)
    {
        while (event = newEvent())
            handleEvent(event);

        updateScene();

        drawGraphics();
        presentGraphics();
    }

    return 0;
}