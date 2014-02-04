#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H

#include <string>
#include <map>
#include <iostream>
#include "GameObject.h"

using namespace std;

class BaseCreator
{
    public:

    virtual GameObject* createGameObject() const = 0;
    virtual ~BaseCreator() {}
};

class GameObjectFactory
{
    public:

        //Constructors                                  //////////////////////
        static GameObjectFactory* Instance()               //////////////////////
        {                                               //////////////////////
            if(s_pInstance == 0)                        //////// SINGLETON ////
            {                                           //////////////////////
                s_pInstance = new GameObjectFactory();     //////////////////////
            }                                           //////////////////////
                                                        //////////////////////
            return s_pInstance;                         //////////////////////
        }

        bool registerType(string typeID, BaseCreator* pCreator); //add types to the map
        GameObject* create(string typeID); //creates a GameObject.


    protected:
    private:

        map<string, BaseCreator*> m_creators; //saves all kind of basecreators
        GameObjectFactory(){}; //now is a SINGLETON
        ~GameObjectFactory();

        static GameObjectFactory* s_pInstance; // Now in GOD-MODE SINGLETON
};

typedef GameObjectFactory TheGameObjectFactory;//Owned SINGLETON

#endif // GAMEOBJECTFACTORY_H
