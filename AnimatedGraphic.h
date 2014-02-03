#ifndef ANIMATEDGRAPHIC_H
#define ANIMATEDGRAPHIC_H

#include "SDLGameObject.h"

class AnimatedGraphic : public SDLGameObject
{
    public:
        AnimatedGraphic(const LoaderParams* pParams, int animSpeed); //constructor

        virtual void draw();
        virtual void update();
        virtual void clean();

    protected:
    private:

        int m_animSpeed;
};

#endif // ANIMATEDGRAPHIC_H
