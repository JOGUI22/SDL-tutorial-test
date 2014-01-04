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
    Game game;

    game.inicialitzar("Chapter 1",100,100,640,480,0);

    while (game.getFuncionant())
    {
        game.tractarEvents();
        game.update();
        game.render();
    }
    game.clean();

    return 0;
}
