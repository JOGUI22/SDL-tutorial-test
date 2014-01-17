#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "SDL2/SDL.h"
#include <iostream>
#include <vector>

using namespace std;

class InputHandler
{
    public:

        static InputHandler* Instance()  // ** begin ** SINGLETON PUBLIC CREATOR
        {
            if(s_pInstance == 0)
            {
                s_pInstance = new InputHandler();
            }

            return s_pInstance; // ** end ** SINGLETON PUBLIC CREATOR
        }

        void update();
        void clean(); //destructor

        void initialiseJoysticks(); //pre: -- //post: initialise joystick handling
        bool joysticksInitialised(); //pre: -- //post: return if joysticks are initialised

    private:

        //Atribute members
        vector<SDL_Joystick* > m_joysticks; //all the connected joysticks
        bool m_bJoysticksInitialised; //are joystick initialisated?

        //Private methods
        InputHandler(); //SINGLETON private constructor
        ~InputHandler(); //SINGLETON private destructor

        //SINGLETON
        static InputHandler* s_pInstance; //the own instance
};

typedef InputHandler TheInputHandler; //only one singleton in all the program

#endif // INPUTHANDLER_H
