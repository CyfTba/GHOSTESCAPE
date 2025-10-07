#ifndef OBJECT_H
#define OBJECT_H
#include "game.h"
class Object{
public:
    Object()=default;
    virtual ~Object()=default;
    virtual void init(){}
    virtual void handleEvents(SDL_Event& event){}
    virtual void update(float dt){}
    virtual void render(){}
    virtual void clean(){}
protected:
    Game& game_=Game::GetInstance();
};



#endif