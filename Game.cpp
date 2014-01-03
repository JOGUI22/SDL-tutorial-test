#include "Game.h"

Game::Game()
{
    m_pRenderer = NULL;
    m_pWindow = NULL;
}

Game::~Game()
{
    //dtor
}

bool Game::inicialitzar(char* title, int xpos, int ypos, int width, int height, Uint32 flags)
{
    //intentem inicialitzar SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "SDL inicialitzat" << endl;
        //init the window
        m_pWindow = SDL_CreateWindow(title , xpos, ypos, width, height, flags);
        if(m_pWindow != 0) // inicialitzar la window
        {
            cout << "SDL window incialitzat" << endl;
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1,0);
            if(m_pRenderer != 0) //renderer incialitzat
            {
                cout << "renderer inicialitzat correctament" << endl;
                SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
            }
            else{
                cout << "renderer inicialitzacio error" << endl;
                return false;
            }
        }
        else{
            cout << "window inicialitzacio error" << endl;
            return false;
        }
    }
    else{
        cout << "SDL inicialitzacio error" << endl;
        return false;
    }
    cout << "incialitacio correcte " << endl;
    funcionant_ = true;

    //inicialitzacio surface-texture
    SDL_Surface* pTempSurface = SDL_LoadBMP("img/pj");
    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer,pTempSurface);
    SDL_FreeSurface(pTempSurface);
    SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h); //guardem a msourceRectangle les dimensions de m_pTexture

    m_destinationRectangle.x = m_sourceRectangle.x = 0;
    m_destinationRectangle.y = m_sourceRectangle.y = 0;
    m_destinationRectangle.w = m_sourceRectangle.w;
    m_destinationRectangle.h = m_sourceRectangle.h;

    return true;
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer); //natejem el renderer

    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);

    SDL_RenderPresent(m_pRenderer); //dibuixar en pantalla
}

void Game::update()
{

}

void Game::tractarEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))//poll pila
    {
        switch (event.type) //triem tipus d'event
        {
        case SDL_QUIT:
            funcionant_ = false;
            break;

        default:
            break;
        }
    }
}

void Game::clean()
{
    cout << "natejem el joc" << endl;
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

bool Game::getFuncionant() const
{
    return funcionant_;
}
