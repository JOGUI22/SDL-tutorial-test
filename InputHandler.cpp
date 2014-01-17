#include "InputHandler.h"
#include "Game.h"

InputHandler* InputHandler::s_pInstance = 0; //IMPORTANT TO MAKE SINGLETON WORK

InputHandler::InputHandler()
{
    //ctor
}

InputHandler::~InputHandler()
{

}

void InputHandler::initialiseJoysticks()
{
    if(SDL_WasInit(SDL_INIT_JOYSTICK) == 0) //check if SDL_INIT_JOYSTICK subsystem is initiate
    {
        SDL_InitSubSystem(SDL_INIT_JOYSTICK); //initiate SDL_INIT_JOYSTICK
    }

    if(SDL_NumJoysticks() > 0) //if there're joysticks...
    {
        for (int i = 0; i < SDL_NumJoysticks(); i++) //for each joystick
        {
            SDL_Joystick* joy = SDL_JoystickOpen(i);
            if (SDL_JoystickOpen(i) != NULL) // try to activate the joystick, otherwise show the error
            {
                m_joysticks.push_back(joy);
            }
            else
            {
                cout << SDL_GetError();
            }
        }
        SDL_JoystickEventState(SDL_ENABLE); //start listening joystick events
        m_bJoysticksInitialised == true;

        cout << "Initialised " << m_joysticks.size() << " joystick(s)" << endl;
    }
    else
    {
        m_bJoysticksInitialised = false;
    }
}

bool InputHandler::joysticksInitialised()
{
    return m_bJoysticksInitialised;
}

void InputHandler::clean()
{
    if(m_bJoysticksInitialised)
    {
        for(int i= 0; i < SDL_NumJoysticks(); i++)
        {
            SDL_JoystickClose(m_joysticks[i]);
        }
    }
}

void InputHandler::update()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            TheGame::Instance()->quit();
        }
    }
}
