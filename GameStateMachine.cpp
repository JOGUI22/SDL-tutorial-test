#include "GameStateMachine.h"

GameStateMachine::GameStateMachine()
{
    //ctor
}

void GameStateMachine::pushState(GameState *pState)
{
    m_gameStates.push_back(pState);
    m_gameStates.back()->onEnter();
}

void GameStateMachine::popState()
{
    if(!m_gameStates.empty())
    {
        if(m_gameStates.back()->onExit())
        {
            delete m_gameStates.back();
            m_gameStates.pop_back();
        }
    }
}

void GameStateMachine::changeState(GameState *pState)
{
    if(!m_gameStates.empty())
    {
        if(m_gameStates.back()->getStateID() == pState->getStateID())
        {
            //do nothing, the last state it's the same as the new one
        }
        if (m_gameStates.back()->onExit())
        {
            delete m_gameStates.back();
            m_gameStates.pop_back();
        }
    }
    //push back new state
    m_gameStates.push_back(pState);

    //initialize it
    m_gameStates.back()->onEnter();

}
