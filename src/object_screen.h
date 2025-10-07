#ifndef OBJECT_SCREEN_H
#define OBJECT_SCREEN_H

#include "object.h"

class ObjectScreen:public Object{

public:
    glm::vec2 getRenderPosition()const{return render_position_;}
    virtual void setRenderPosition(const glm::vec2& pos){render_position_=pos;}

protected:
    glm::vec2 render_position_=glm::vec2(0);//渲染(屏幕)位置

};













#endif