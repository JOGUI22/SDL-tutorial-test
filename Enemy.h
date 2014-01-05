#ifndef ENEMY_H
#define ENEMY_H

#include "SDLGameObject.h"
#include <SDL2/SDL.h>

class Enemy : public SDLGameObject //inherit from GameObject
{
    public:
        Enemy(const LoaderParams* pParams);

        virtual void draw(); //draw player
        virtual void update(); //update status/info player
        virtual void clean (); //destructor

    protected:
    private:
};

#endif // ENEMY_H
