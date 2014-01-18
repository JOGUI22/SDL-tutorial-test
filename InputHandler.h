#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "SDL2/SDL.h"
#include <iostream>
#include <vector>
#include "Vector2D.h"

using namespace std;

enum mouse_buttons
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

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

        int xvalue(int joy, int stick); //pre: joy is the joystick ID, stick 1 is left, stick 2 is right //post: return x value
        int yvalue(int joy, int stick); //pre: joy is the joystick ID, stick 1 is left, stick 2 is right //post: return y value

        //GET METHODS
        bool getJoyButtonState(int joy, int buttonNumber); //get the state of the buttonNumber from joy.
        bool getMouseButtonState(int buttonNumber); //get the state of the buttonNumber from mouse
        Vector2D* getMousePosition(); //get the actual Vector2D coords of the mouse in the window
        bool isKeyDown(SDL_Scancode key); //check if a keyboard key is down

    private:

        //Atribute members
        vector<SDL_Joystick* > m_joysticks; //all the connected joysticks
        bool m_bJoysticksInitialised; //are joystick initialisated?
        vector<pair<Vector2D*, Vector2D* > > m_joystickValues; //values of axis joystic
        vector< vector<bool> > m_buttonStates; //matrix with buttons input
        vector<bool> m_mouseButtonStates; //vector with the state of mouse buttons
        Vector2D* m_mousePosition; //vector with the actual position in the window of the cursor(mouse)
        const Uint8* m_keystates;

        //SINGLETON
        static InputHandler* s_pInstance; //the own instance

        //Constants
        const int m_joystickDeadZone = 10000; //Value has to change accordingly to the controller type


        //Private methods
        InputHandler(); //SINGLETON private constructor
        ~InputHandler(); //SINGLETON private destructor

        //Private functions to handle different event types

        //handle keyboard events
        void onKeyDown();
        void onKeyUp();

        //handle mpuse events
        void onMouseMove(SDL_Event& event);
        void onMouseButtonDown(SDL_Event& event);
        void onMouseButtonUp(SDL_Event& event);

        //handle joysticks events
        void onJoystickAxisMove(SDL_Event& event);
        void onJoystickButtonDown(SDL_Event& event);
        void onJoystickButtonUp(SDL_Event& event);

        };

typedef InputHandler TheInputHandler; //only one singleton in all the program

#endif // INPUTHANDLER_H
