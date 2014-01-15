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
    m_position.setX(m_position.getX() - 1);
    m_currentFrame = int((SDL_GetTicks() / 100) % 6);
}

void Player::clean()
{

}
