#include "GameObjectFactory.h"

GameObjectFactory* GameObjectFactory::s_pInstance = 0;

bool GameObjectFactory::registerType(string typeID, BaseCreator* pCreator)
{
    map<string, BaseCreator*>::iterator it = m_creators.find(typeID);

    //if the type is already registered, do nothing
    if(it != m_creators.end())
    {
        delete pCreator;
        return false;
    }

    m_creators[typeID] = pCreator;
    return true;
}

GameObject* GameObjectFactory::create(string typeID)
{
    map<string, BaseCreator*>::iterator it = m_creators.find(typeID);

    if(it == m_creators.end())
    {
        cout << "could not find type: " << typeID << endl;
        return NULL;
    }

    BaseCreator* pCreator = it->second;
    return pCreator->createGameObject();
}
