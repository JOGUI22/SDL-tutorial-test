#include "Enemy.h"

Enemy::Enemy()
{
    //ctor
}

void Enemy::load(int x, int y, int width, int height, string textureID)
{
    GameObject::load(x, y, width, height, textureID);
}

void Enemy::draw(SDL_Renderer* pRenderer)
{
    GameObject::draw(pRenderer); //example inherance call
}

void Enemy::update()
{
    m_x ++;
    m_y ++;
    m_currentFrame = int((SDL_GetTicks() / 100) % 6);
}

void Enemy::clean()
{
    GameObject::clean();
    cout << "clean player" << endl;
}
