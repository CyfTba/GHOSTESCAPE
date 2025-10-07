#ifndef PLAYER_H
#define PLAYER_H

#include "actor.h"

class Player:public Actor{
public:
    virtual void init()override;
    virtual void handleEvents(SDL_Event& event)override;
    virtual void update(float dt)override;
    virtual void render()override;
    virtual void clean()override;

    void keyboardControl();
    void move(float dt);
    void syncCameraPosition();
};

#endif