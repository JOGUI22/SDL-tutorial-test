#include "Player.h"

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

    m_currentFrame = int((SDL_GetTicks() / 100) % 6);

    m_acceleration.setX(1);

    SDLGameObject::update(); //call the up-class
}

void Player::clean()
{

}
