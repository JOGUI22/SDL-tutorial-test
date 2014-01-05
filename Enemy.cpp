#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
    //ctor
}


void Enemy::draw()
{
    SDLGameObject::draw(); //example inherance call
}

void Enemy::update()
{
    m_x ++;
    m_y ++;
    m_currentFrame = int((SDL_GetTicks() / 100) % 6);
}

void Enemy::clean()
{

}
