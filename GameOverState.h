#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include "GameState.h"
#include "AnimatedGraphic.h"
#include <vector>
#include <iostream>

using namespace std;

class GameOverState : public GameState
{
    public:
        GameOverState();

        virtual void update();
        virtual void render();

        virtual bool onEnter();
        virtual bool onExit();

        //GETs
        virtual string getStateID() const;

    protected:
    private:

        //private methods:
        static void s_gameOverToMain(); //changes GameState to Main Menu
        static void s_restartPlay(); //Reset PlayState

        static const string s_gameOverID; //string identificator ID of the state

        vector<GameObject*> m_gameObjects; //container with all the gameObjects
};

#endif // GAMEOVERSTATE_H
