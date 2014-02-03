#include "MenuState.h"
#include "TextureManager.h"
#include "Game.h"
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
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void MenuState::render()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
}

bool MenuState::onEnter()
{
    if(!TheTextureManager::Instance()->load("img/button.png","playbutton", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if(!TheTextureManager::Instance()->load("img/exit.png","exitbutton", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    GameObject* button1 = new MenuButton(new LoaderParams(100, 100, 400, 100, 3, "playbutton"), s_menuToPlay);
    GameObject* button2 = new MenuButton(new LoaderParams(100,300, 400, 100, 3, "exitbutton"), s_exitFromMenu);

    m_gameObjects.push_back(button1);
    m_gameObjects.push_back(button2);

    cout << "entering MenuState" << endl;
    return true;
}

bool MenuState::onExit()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();
    TheTextureManager::Instance()->clearFromTextureMap("playbutton"); //clean from TM
    TheTextureManager::Instance()->clearFromTextureMap("exitbutton"); //clean from TM
    cout << "exiting MenuState" << endl;
    return true;
}

void MenuState::s_menuToPlay()
{
    cout << "Play button clicked" << endl; //Go to play GameState
    TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitFromMenu()
{
    TheGame::Instance()->quit(); //Exit game.
    cout << "Exit button clicked" << endl;
}
