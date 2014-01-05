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
    //try init SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "SDL inicialitzat" << endl;
        //init the window
        m_pWindow = SDL_CreateWindow(title , xpos, ypos, width, height, flags);
        if(m_pWindow != 0) // init window
        {
            cout << "SDL window incialitzat" << endl;
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1,0);
            if(m_pRenderer != 0) //renderer init
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
    m_funcionant = true;

    //load images/sprites on database;
    TextureManager::Instance()->load("img/animate-alpha.png", "animate_dog", m_pRenderer);

    //Initialize GameObjects
    m_go = new GameObject();
    m_player = new Player();
    m_enemy = new Enemy();

    m_go->load(100, 100, 128, 82, "animate_dog");
    m_player->load(300, 300, 128, 82, "animate_dog");
    m_enemy->load(0, 0, 128, 82, "animate_dog");

    m_gameObjects.push_back(m_go);
    m_gameObjects.push_back(m_player);
    m_gameObjects.push_back(m_enemy);

    // no necessari ara mateix // SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h); //guardem a msourceRectangle les dimensions de m_pTexture

    SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
    return true;
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer); //clean renderer

    //actual render images
    for(int i = 0; i < m_gameObjects.size(); i++) //we draw all gameObject images
    {
        m_gameObjects[i]->draw(m_pRenderer); //virtual GameObject methods allow us to use the propper inner level class method.
    }

    ///////////////////
    SDL_RenderPresent(m_pRenderer); //draw in window
}

void Game::update()
{
    for (int i = 0; i < m_gameObjects.size(); i++)//we update all gameObjects
    {
        m_gameObjects[i]->update(); //virtual GameObject methods allow us to use the propper inner level class methods
    }
}

void Game::tractarEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))//poll pila
    {
        switch (event.type) //triem tipus d'event
        {
        case SDL_QUIT:
            m_funcionant = false;
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
    return m_funcionant;
}
