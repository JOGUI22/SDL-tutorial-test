#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject (pParams)
{
    m_position = Vector2D(pParams->getX(), pParams->getY());
    m_width = pParams->getWidth();
    m_height = pParams->getHeight();
    m_textureID = pParams->getTextureID();

    m_currentRow = 1;
    m_currentFrame = 1;
}

void SDLGameObject::draw()
{
    TextureManager::Instance()->drawFrame(m_textureID, int(m_position.getX()), int(m_position.getY()), m_width,
                                          m_height, m_currentRow, m_currentFrame,
                                          TheGame::Instance()->getRenderer());
}

void SDLGameObject::update()
{

}

void SDLGameObject::clean()
{

}
