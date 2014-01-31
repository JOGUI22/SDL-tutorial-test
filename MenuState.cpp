#include "MenuState.h"
#include <iostream>
using namespace std;

const string MenuState::s_menuID = "MENU";

MenuState::MenuState()
{

}

string MenuState::getStateID() const
{
    return s_menuID;
}

void MenuState::update()
{
    //nothing for now
}

void MenuState::render()
{
    //nothig for now
}

bool MenuState::onEnter()
{
    cout << "entering MenuState" << endl;
    return true;
}

bool MenuState::onExit()
{
    cout << "exiting MenuState" << endl;
    return true;
}
