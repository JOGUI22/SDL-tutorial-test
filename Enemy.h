#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"


class Enemy : public GameObject //inherit from GameObject
{
    public:
        Enemy();

        void load(int x, int y, int width, int height, string textureID);
        void draw(SDL_Renderer* pRenderer); //draw player
        void update(); //update status/info player
        void clean (); //destructor

    protected:
    private:
};

#endif // ENEMY_H
