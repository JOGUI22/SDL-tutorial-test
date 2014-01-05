#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"


class Player : public GameObject // inherit from GameObject
{
    public:
        Player();

        void load(int x, int y, int width, int height, string textureID);
        void draw(SDL_Renderer* pRenderer); //draw player
        void update(); //update status/info player
        void clean (); //destructor

    protected:
    private:
};

#endif // PLAYER_H
