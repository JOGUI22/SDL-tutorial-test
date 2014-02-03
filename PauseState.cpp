#include "PauseState.h"
#include "Game.h"
#include "TextureManager.h"

const string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain()
{
    TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}

void PauseState::s_resumePlay()
{
    TheGame::Instance()->getStateMachine()->popState();
}

void PauseState::update()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void PauseState::render()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
}

bool PauseState::onEnter()
{
    if(!TheTextureManager::Instance()->load("img/resume.png", "resumebutton", TheGame::Instance()->getRenderer()))
    {
        return false; //can't load texutre, error
    }
    if (!TheTextureManager::Instance()->load("img/main.png", "mainbutton", TheGame::Instance()->getRenderer()))
    {
        return false; //can't load texture, error
    }

    GameObject* button1 = new MenuButton(new LoaderParams(200, 100, 200, 80, "mainbutton"), s_pauseToMain);
    GameObject* button2 = new MenuButton(new LoaderParams(200, 300, 200, 80, "resumebutton"), s_resumePlay);

    m_gameObjects.push_back(button1);
    m_gameObjects.push_back(button2);

    cout << "entering PauseState" << endl;
    return true;
}

bool PauseState::onExit()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();

    TheTextureManager::Instance()->clearFromTextureMap("resumebutton");
    TheTextureManager::Instance()->clearFromTextureMap("mainbutton");

    cout << "exiting PauseState" << endl;
    return true;
}

string PauseState::getStateID() const
{
    return s_pauseID;
}
