#ifndef SDLGAMEOBJECT_H
#define SDLGAMEOBJECT_H

#include "GameObject.h"
#include "TextureManager.h"
#include "Vector2D.h"


class SDLGameObject : public GameObject //Inherance from ABSTRACT GameObject
{
    public:
        SDLGameObject(const LoaderParams* pParams);

        virtual void draw();
        virtual void update();
        virtual void clean();

    protected:

        Vector2D m_position; //controls position of the GameObject
        Vector2D m_velocity; //controls velocity of the GameObject
        Vector2D m_acceleration; //controls acceleration of the GameObject

        int m_width;
        int m_height;

        int m_currentRow;
        int m_currentFrame;

        string m_textureID;

};

#endif // SDLGAMEOBJECT_H
