#include "TextureManager.h"

TextureManager::TextureManager()
{
    //ctor
}

TextureManager::~TextureManager()
{
    //dtor
}

bool TextureManager::load(string fileName, string id, SDL_Renderer* pRenderer)
{
    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str()); //create Surface with contents of fileName

    if(pTempSurface == 0) //exception handle load error
    {
        cout << "error loading file: " << fileName << endl;
        return false;
    }

    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface); //Pass Surface to Texture
    SDL_FreeSurface(pTempSurface); //Delete Surface

    if(pTexture == 0) //exception handle transiction Surfacte to Texture
    {
        cout << "error creating Texture of file: " << fileName << endl;
        return false;
    }

    m_textureMap[id] = pTexture; //save texture.
    return true;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect; //source rectangle
    SDL_Rect destRect; //destination rectangle

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x; //select x axis on game window
    destRect.y = y; //select y axis on game window

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip); //Load image to render buffer.
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect; //source rectangle
    SDL_Rect destRect; //destination rectangle

    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip); //Load current frame on the buffer game.
}
