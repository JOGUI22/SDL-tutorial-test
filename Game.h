#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "TextureManager.h"
#include "GameObject.h"
#include "Enemy.h"
#include "Player.h"
#include "GameStateMachine.h"
#include "MenuState.h"
#include "PlayState.h"


using namespace std;

class Game //SINGLETON
{
    public:

        //SINGLETON creation
        static Game* Instance()
        {
            if(s_pInstance == 0)
            {
                s_pInstance = new Game();
                return s_pInstance;
            }
            return s_pInstance;
        }
        SDL_Renderer* getRenderer() const {return m_pRenderer;}

        //Constructors

        ~Game();

        //Game methods
        bool init(char* title, int xpos, int ypos, int width, int height, Uint32 flags); //conjunt de coses que configurar al iniciar el programa
        void render(); //conjunt de coses que fan veure en pantalla
        void update();//actualitzacions bufferianes
        void handleEvents();//tractament de evenets (inputs)
        void clean();//delete
        void quit();//calls clean

        //GETs
        bool running() const;
        GameStateMachine* getStateMachine();


    private:

        //SINGLETON transformation
        Game();
        static Game* s_pInstance;

        //Atributs
        bool m_running; //Atribut per mirar si continua el loop del joc.
        SDL_Window* m_pWindow; //Window del joc.
        SDL_Renderer* m_pRenderer; //Renderer del joc.
        GameStateMachine* m_pGameStateMachine; //ACTUAL GAMESTATEMACHINE

};

typedef Game TheGame;

#endif // GAME_H
