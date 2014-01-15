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
    m_acceleration.setX(1);
    m_acceleration.setY(1);
    m_currentFrame = int((SDL_GetTicks() / 100) % 6);

    SDLGameObject::update();
}

void Enemy::clean()
{

}
