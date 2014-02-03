#include "GameOverState.h"
#include "Game.h"
#include "TextureManager.h"

const string GameOverState::s_gameOverID = "GAMEOVER";

GameOverState::GameOverState()
{

}

void GameOverState::s_gameOverToMain()
{
    TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}

void GameOverState::s_restartPlay()
{
    TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void GameOverState::update()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void GameOverState::render()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
}

bool GameOverState::onEnter()
{
    if(!TheTextureManager::Instance()->load("img/gameover.png", "gameovertext", TheGame::Instance()->getRenderer()))
    {
        return false; //can't load texutre, error
    }
    if (!TheTextureManager::Instance()->load("img/main.png", "mainbutton", TheGame::Instance()->getRenderer()))
    {
        return false; //can't load texture, error
    }
    if(!TheTextureManager::Instance()->load("img/restart.png", "restartbutton", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    GameObject* gameOverText = new AnimatedGraphic(new LoaderParams(200, 100, 190, 30, 2, "gameovertext"), 2);
    GameObject* button1 = new MenuButton(new LoaderParams(200, 200, 200, 80, 3, "mainbutton"), s_gameOverToMain);
    GameObject* button2 = new MenuButton(new LoaderParams(200, 300, 200, 80, 3, "restartbutton"), s_restartPlay);

    m_gameObjects.push_back(gameOverText);
    m_gameObjects.push_back(button1);
    m_gameObjects.push_back(button2);

    cout << "entering GameOverState" << endl;
    return true;
}

bool GameOverState::onExit()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();

    TheTextureManager::Instance()->clearFromTextureMap("resumebutton");
    TheTextureManager::Instance()->clearFromTextureMap("mainbutton");

    cout << "exiting GameOverState" << endl;
    return true;
}

string GameOverState::getStateID() const
{
    return s_gameOverID;
}

