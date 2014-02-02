#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) //inherance from SDLGameObject
{
    //ctor
}

void Player::draw()
{
    SDLGameObject::draw(); //SDLGameObject draw function
}

void Player::update()
{
    m_velocity.setX(0);
    m_velocity.setY(0);

    handleInput();

    m_currentFrame = int((SDL_GetTicks() / 100) % 5);

    SDLGameObject::update(); //call the up-class
}

void Player::clean()
{

}

void Player::handleInput()
{
    if (TheInputHandler::Instance()->joysticksInitialised())
    {
        if(TheInputHandler::Instance()->xvalue(0,1) or TheInputHandler::Instance()->xvalue(0,1) < 0)
        {
            m_velocity.setX(1* TheInputHandler::Instance()->xvalue(0,1));
        }
        if(TheInputHandler::Instance()->yvalue(0,1) or TheInputHandler::Instance()->yvalue(0,1) < 0)
        {
            m_velocity.setY(1* TheInputHandler::Instance()->yvalue(0,1));
        }
        if(TheInputHandler::Instance()->xvalue(0,2) or TheInputHandler::Instance()->xvalue(0,2) < 0)
        {
            m_velocity.setX(1* TheInputHandler::Instance()->xvalue(0,2));
        }
        if(TheInputHandler::Instance()->yvalue(0,2) or TheInputHandler::Instance()->yvalue(0,2) < 0)
        {
            m_velocity.setY(1* TheInputHandler::Instance()->yvalue(0,2));
        }
        if(TheInputHandler::Instance()->getJoyButtonState(0,3))
        {
            m_velocity.setX(1);
        }
    }
    if(TheInputHandler::Instance()->getMouseButtonState(LEFT))
    {
        m_velocity.setX(1);
    }
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
    {
        m_velocity.setX(2);
    }
     if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
    {
        m_velocity.setX(-2);
    }
     if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
    {
        m_velocity.setY(-2);
    }
     if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
    {
        m_velocity.setY(2);
    }
}
