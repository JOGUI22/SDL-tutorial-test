#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <string>

#include "Game.h"

//MAIN CONSTANTS
const int FPS = 60; ///////////////////_______________////
const int DELAY_TIME = 1000.0f / FPS;//fixed framerate////

using namespace std;

int main ( int argc, char** argv )
{
    Uint32 frameStart, frameTime;

    if(TheGame::Instance()->init("Chapter 1", 100, 100, 640, 480, 0))
    {
        while (TheGame::Instance()->running())
        {
            frameStart = SDL_GetTicks(); //fixed frame rate var

            TheGame::Instance()->handleEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();

            frameTime = SDL_GetTicks() - frameStart; //fixed frame rate var

            if (frameTime < DELAY_TIME) //fixed frame rate
            {
                SDL_Delay((int)(DELAY_TIME - frameTime)); //delay to achieve fixed frame rate
            }
        }
        TheGame::Instance()->clean();
    }

    return 0;
}
