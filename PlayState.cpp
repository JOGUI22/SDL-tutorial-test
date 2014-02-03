#include "PlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "InputHandler.h"
#include <iostream>

const string PlayState::s_playID = "PLAY";

using namespace std;

PlayState::PlayState()
{
    //ctor
}

void PlayState::update()
{
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        TheGame::Instance()->getStateMachine()->pushState(new PauseState());
    }
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void PlayState::render()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
}

bool PlayState::onEnter()
{
    if(!TheTextureManager::Instance()->load("img/helicopter.png","helicopter", TheGame::Instance()->getRenderer())) //can't load images
    {
        return false;
    }
    GameObject* player = new Player (new LoaderParams(100, 100, 128, 55, "helicopter"));
    m_gameObjects.push_back(player);

    cout << "Entering PlayState" << endl;
    return true;
}

bool PlayState::onExit()
{
    for (int i = 0; i < m_gameObjects.size(); i++) //clear all existing gameObjects
    {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear(); //clear vector

    //clean textures
    TheTextureManager::Instance()->clearFromTextureMap("helicopter");

    cout << "exiting PlayState " << endl;
    return true;
}

string PlayState::getStateID() const
{
    return s_playID;
}
