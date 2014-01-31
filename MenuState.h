#ifndef MENUSTATE_H
#define MENUSTATE_H

using namespace std;

#include <string>
#include "GameState.h"

class MenuState : public GameState
{
    public:
        MenuState();

        virtual void update();
        virtual void render();

        virtual bool onEnter();
        virtual bool onExit();

        virtual string getStateID() const;
    protected:
    private:

        static const string s_menuID;
};

#endif // MENUSTATE_H
