#ifndef GAMESTATEMACHINE_H
#define GAMESTATEMACHINE_H

using namespace std;

#include <vector>
#include "GameState.h"

class GameStateMachine //manages all gamestates
{
    public:
        GameStateMachine();

        void pushState(GameState* pState); //add state without removing the previous state
        void changeState(GameState* pState); //remove current state and change adding another
        void popState(); //remove current state without adding another
    protected:
    private:

        vector<GameState*> m_gameStates; //polymorphism
};

#endif // GAMESTATEMACHINE_H
