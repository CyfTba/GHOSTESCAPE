#ifndef ACTOR_H
#define ACTOR_H

#include "object_world.h"
class Actor:public ObjectWorld{
    protected:
        glm::vec2 velocity_=glm::vec2(0);//速度
        float max_speed_=500.0f;//最大速度
        glm::vec2 move_vector_=glm::vec2(0);//移动向量
    public:
        glm::vec2 getVelocity()const{return velocity_;}
        void setVelocity(const glm::vec2& vel){velocity_=vel;}
        float getMaxSpeed()const{return max_speed_;}
        void setMaxSpeed(float speed){max_speed_=speed;}
       
};







#endif