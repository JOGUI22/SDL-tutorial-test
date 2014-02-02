#ifndef MENUSTATE_H
#define MENUSTATE_H

using namespace std;

#include <string>
#include "GameState.h"
#include <vector>
#include "GameObject.h"
#include "MenuButton.h"

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

        static const string s_menuID; //name of the class
        vector<GameObject*> m_gameObjects; //container for GameObjects

        //call back functions for menu item, works for use as pointers of the MenuButton
        static void s_menuToPlay();
        static void s_exitFromMenu();
};

#endif // MENUSTATE_H
