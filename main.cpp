#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <string>

#include "Game.h"

using namespace std;

int main ( int argc, char** argv )
{
    if(TheGame::Instance()->inicialitzar("Chapter 1", 100, 100, 640, 480, 0))
    {
        while (TheGame::Instance()->getFuncionant())
        {
            TheGame::Instance()->tractarEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();

            SDL_Delay(10);
        }
        TheGame::Instance()->clean();
    }

    return 0;
}
