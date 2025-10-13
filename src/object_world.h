#ifndef OBJECT_WORLD_H
#define OBJECT_WORLD_H

#include "object_screen.h"

class ObjectWorld:public ObjectScreen{

protected:
    glm::vec2 position_=glm::vec2(0);//玩家及物体在世界中的位置
public:
    glm::vec2 getPosition()const{return position_;}
    void setPosition(const glm::vec2& pos);
    virtual void setRenderPosition(const glm::vec2& pos)override;
    virtual void update(float dt)override;
    virtual void init()override{type_=ObjectType::OBJECT_WORLD;}
};









#endif