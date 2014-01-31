#ifndef GAMESTATE_H
#define GAMESTATE_H

using namespace std;

#include <string>

class GameState //VIRTUAL class with GameState blueprint
{
    public:
        GameState();

        virtual void update() = 0;
        virtual void render() = 0;

        virtual bool onEnter() = 0; //like a load function
        virtual bool onExit() = 0;  //like a clena function

        virtual string getStateID() const = 0;
    protected:
    private:
};

#endif // GAMESTATE_H
