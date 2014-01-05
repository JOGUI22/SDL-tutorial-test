#ifndef LOADERPARAMS_H
#define LOADERPARAMS_H

#include <string>

using namespace std;

class LoaderParams //This class load to abstract classes the right information
{
    public:
        LoaderParams(int x, int y, int width, int height, string textureID) : m_x(x),
                                        m_y(y), m_width(width), m_height(height), m_textureID(textureID)
        {

        }

        int getX() const { return m_x; }
        int getY() const { return m_y; }
        int getWidth() const { return m_width; }
        int getHeight() const { return m_height; }
        string getTextureID() const { return m_textureID; }


    private:

        int m_x;
        int m_y;

        int m_width;
        int m_height;

        string m_textureID;
};

#endif // LOADERPARAMS_H
