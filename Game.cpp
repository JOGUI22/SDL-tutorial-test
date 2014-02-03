#include "Game.h"
#include "InputHandler.h"


Game* Game::s_pInstance = 0;

Game::Game()
{
    m_pRenderer = NULL;
    m_pWindow = NULL;
}

Game::~Game()
{
    //dtor
}

bool Game::init(char* title, int xpos, int ypos, int width, int height, Uint32 flags)
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
    m_running = true;

    //joystick handling
    TheInputHandler::Instance()->initialiseJoysticks();

    //
    SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

    //init of GameStateMachine
    m_pGameStateMachine = new GameStateMachine();
    m_pGameStateMachine->changeState(new MenuState());

    //end
    return true;
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer); //clean renderer

    //actual render images
    m_pGameStateMachine->render();

    ///////////////////
    SDL_RenderPresent(m_pRenderer); //draw in window
}

void Game::update()
{
    m_pGameStateMachine->update();
}

void Game::handleEvents()
{
    TheInputHandler::Instance()->update();

    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
    {
        m_pGameStateMachine->changeState(new PlayState());
    }
}

void Game::quit()
{
    clean();
}

void Game::clean()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    TheInputHandler::Instance()->clean();
    SDL_Quit();
}

bool Game::running() const
{
    return m_running;
}

GameStateMachine* Game::getStateMachine()
{
    return m_pGameStateMachine;
}
