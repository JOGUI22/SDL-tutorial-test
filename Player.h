#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
    public:
        Player(const LoaderParams* pParams);

        virtual void draw(); //draw player
        virtual void update(); //update status/info player
        virtual void clean (); //destructor
    protected:
    private:
};

#endif // PLAYER_H
