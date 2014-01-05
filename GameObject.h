#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "TextureManager.h">

using namespace std;

class GameObject
{
    public:
        GameObject();

        void load(int x, int y, int width, int height, string textureID); //load. get ready.
        void draw(SDL_Renderer* pRenderer); //draw in screen
        void update(); //update status/information of this
        void clean(); //destructor

    protected: //we want some use with his family-object

        string m_textureID; //ID with the texture located in the TextureManager classs.

        int m_currentFrame; //current frame active (only for sprites)
        int m_currentRow;   //advanced functionallity for interactive sprites

        int m_x; //atribute pos x
        int m_y; //atribute pos y

        int m_width; //atribute width
        int m_height; //atribute height
    private:
};

#endif // GAMEOBJECT_H
