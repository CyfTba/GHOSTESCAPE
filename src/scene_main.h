#ifndef SCENE_MAIN_H
#define SCENE_MAIN_H

#include "scene.h"
#include "player.h"

class Scene_Main:public Scene{
public:
    Scene_Main()=default;
    virtual ~Scene_Main()=default;
    virtual void init()override;
    virtual void handleEvents(SDL_Event& event)override;
    virtual void update(float dt)override;
    virtual void render()override;
    virtual void clean()override;
    
private:

    void drawBackground();
    Player* player_=nullptr;//玩家
};









#endif