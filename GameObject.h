#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "LoaderParams.h"

using namespace std;

class GameObject //ABSTRACT CLASS (we force all derived classe to have this methods.
{
    public:
        GameObject();

        virtual void draw()=0;
        virtual void update()=0;
        virtual void clean()=0;

    protected: //we want some use with his family-object

        GameObject(const LoaderParams* pParams){} //strange constructor
        virtual ~GameObject() {} //destructor
    private:
};

#endif // GAMEOBJECT_H
