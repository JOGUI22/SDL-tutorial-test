#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include <vector>
#include <iostream>
#include "GameState.h"
#include "GameObject.h"

using namespace std;


class PauseState : public GameState
{
    public:

        virtual void update(); //update subrutines
        virtual void render(); //render subrutines

        virtual bool onEnter(); //activates when game enter in this state
        virtual bool onExit();  //activates when game leaves this state

        //GETs
        virtual string getStateID() const;
    protected:
    private:

        //private methods
        static void s_pauseToMain(); //changes gameState to the main menu
        static void s_resumePlay(); //changes gameState to the play level

        //Atributes
        static const string s_pauseID; //name identificator (ID) of the state.

        vector <GameObject*> m_gameObjects; //container with all the gameObjects
};

#endif // PAUSESTATE_H
