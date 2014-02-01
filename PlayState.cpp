#include "PlayState.h"
#include <iostream>

const string PlayState::s_playID = "PLAY";

using namespace std;

PlayState::PlayState()
{
    //ctor
}

void PlayState::update()
{
    //nothing for now
}

void PlayState::render()
{
    //nothing for now
}

bool PlayState::onEnter()
{
    cout << "entering PlayState" << endl;
    return true;
}

bool PlayState::onExit()
{
    cout << "exiting PlayState " << endl;
    return true;
}

string PlayState::getStateID() const
{
    return s_playID;
}
