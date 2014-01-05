#include "Player.h"

Player::Player()
{
    //ctor
}

void Player::load(int x, int y, int width, int height, string textureID)
{
    GameObject::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer* pRenderer)
{
    GameObject::draw(pRenderer); //example inherance call
}

void Player::update()
{
    m_x --;
    m_currentFrame = int((SDL_GetTicks() / 100) % 6);
}

void Player::clean()
{
    GameObject::clean();
    cout << "clean player" << endl;
}
