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
    //input behaviour
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        TheGame::Instance()->getStateMachine()->pushState(new PauseState());
    }

    //update GameObjects
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }

    //Collision detection
    if(checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0]), dynamic_cast<SDLGameObject*>(m_gameObjects[1])))
    {
        TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
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
    if(!TheTextureManager::Instance()->load("img/helicopter2.png", "helicopter2", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    GameObject* player = new Player (new LoaderParams(100, 100, 128, 55, 5, "helicopter"));
    GameObject* enemy = new Enemy (new LoaderParams(500, 100, 128, 55, 5, "helicopter2"));
    m_gameObjects.push_back(player);
    m_gameObjects.push_back(enemy);

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

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate sides of rect b
    leftA = p1->getPosition().getX();
    rightA = p1->getPosition().getX() + p1->getWidth();
    topA = p1->getPosition().getY();
    bottomA = p1->getPosition().getY() + p1->getHeight();

    //Calculate sides of rect b
    leftB = p2->getPosition().getX();
    rightB = p2->getPosition().getX() + p2->getWidth();
    topB = p2->getPosition().getY();
    bottomB = p2->getPosition().getY() + p2->getHeight();

    //check collision
    if (bottomA <= topB or topA >= bottomB or rightA <= leftB or leftA >= rightB) //no collision
        return false;
    else
        return true;

}
