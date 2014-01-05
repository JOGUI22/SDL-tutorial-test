#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

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

        //POLYMORFISM OBJECTS (have it declared allow us to create them everywhere
        GameObject* m_go;
        GameObject* m_player;
        GameObject* m_enemy;

        //STL containers
        vector<GameObject*> m_gameObjects; //saves all gameObjects
};

#endif // GAME_H
