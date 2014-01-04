#ifndef GAME_H
#define GAME_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "TextureManager.h"

using namespace std;

class Game
{
    public:
        //Constructors
        Game();
        ~Game();

        //Game metodes
        bool inicialitzar(char* title, int xpos, int ypos, int width, int height, Uint32 flags); //conjunt de coses que configurar al iniciar el programa
        void render(); //conjunt de coses que fan veure en pantalla
        void update();//actualitzacions bufferianes
        void tractarEvents();//tractament de evenets (inputs)
        void clean();//delete

        //Consultors.
        bool getFuncionant() const;


    private:

        //Atributs
        bool m_funcionant; //Atribut per mirar si continua el loop del joc.
        SDL_Window* m_pWindow; //Window del joc.
        SDL_Renderer* m_pRenderer; //Renderer del joc.

        int m_currentFrame;
        TextureManager m_textureManager;
};

#endif // GAME_H
