#ifndef SDLGAMEOBJECT_H
#define SDLGAMEOBJECT_H

#include "GameObject.h"
#include "Game.h"

class SDLGameObject : public GameObject //Inherance from ABSTRACT GameObject
{
    public:
        SDLGameObject(const LoaderParams* pParams);

        virtual void draw();
        virtual void update();
        virtual void clean();

    protected:

        int m_x;
        int m_y;

        int m_width;
        int m_height;

        int m_currentRow;
        int m_currentFrame;

        string m_textureID;

};

#endif // SDLGAMEOBJECT_H
