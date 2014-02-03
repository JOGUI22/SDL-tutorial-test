#ifndef PLAYSTATE_H
#define PLAYSTATE_H

using namespace std;

#include "GameState.h"
#include <string>
#include <vector>
#include "GameObject.h"
#include "PauseState.h"
#include "SDLGameObject.h"
#include "GameOverState.h"


class PlayState : public GameState
{
    public:
        PlayState();
        virtual void update();
        virtual void render();

        virtual bool onEnter();
        virtual bool onExit();

        virtual string getStateID() const;
    protected:
    private:

        //Private methods:
        bool checkCollision(SDLGameObject* p1, SDLGameObject* p2); //checks collision between p1 and p2

        //Atributes:
        static const string s_playID; //string ID identificator
        vector<GameObject*> m_gameObjects; //vector with all the gameObjects
};

#endif // PLAYSTATE_H
