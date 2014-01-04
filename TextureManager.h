#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include<map>
#include<string>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>

using namespace std;

class TextureManager
{
    public:
        //Constructors
        TextureManager();
        ~TextureManager();

        //Metodes
        bool load(string fileName, string id, SDL_Renderer* pRenderer); //Load the image with the fileName, and assigns an id.

        void draw (string id, int x, int y, int width, int height,
                   SDL_Renderer* pRenderer, SDL_RendererFlip = SDL_FLIP_NONE); //draw the static image.

        void drawFrame(string id, int x, int y, int width, int height,
                       int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE); //draw image sprite

    private:
        map<string, SDL_Texture*> m_textureMap; //map with all the SDL_Textures
};

#endif // TEXTUREMANAGER_H
