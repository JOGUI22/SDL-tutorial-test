#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include "SDLGameObject.h"

class MenuButton : public SDLGameObject
{
    public:
        MenuButton(const LoaderParams* pParams, void (*callback)());

        virtual void draw();
        virtual void update();
        virtual void clean();
    protected:
    private:

        enum button_state //enumerator with the posible states of the button
        {
            MOUSE_OUT = 0,
            MOUSE_OVER = 1,
            CLICKED = 2
        };

        void (*m_callback)(); //pointer to a function
        bool m_bReleased; // better state button handling

};

#endif // MENUBUTTON_H
