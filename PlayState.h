#ifndef PLAYSTATE_H
#define PLAYSTATE_H

using namespace std;

#include "GameState.h"
#include <string>


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

        static const string s_playID;
};

#endif // PLAYSTATE_H
