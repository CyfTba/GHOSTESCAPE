#ifndef SCENE_H
#define SCENE_H

#include"object.h"
#include "glm/glm.hpp"
#include <vector>
class Scene:public Object{
public:
    Scene()=default;
    virtual ~Scene()=default;
    virtual void init()override{}
    virtual void handleEvents(SDL_Event& event)override{}
    virtual void update(float dt)override{}
    virtual void render()override{}
    virtual void clean()override{}
    glm::vec2 WorldToScreen(const glm::vec2& world_pos)const{return world_pos - camera_position_;}//世界坐标转屏幕坐标
    glm::vec2 ScreenToWorld(const glm::vec2& screen_pos)const{return screen_pos + camera_position_;}//屏幕坐标转世界坐标 
    glm::vec2 getCameraPosition()const{return camera_position_;}
    void setCameraPosition(const glm::vec2& pos);
    glm::vec2 getWorldSize()const{return world_size_;}
    void setWorldSize(const glm::vec2& size){world_size_=size;}
protected:
    glm::vec2 camera_position_=glm::vec2(0);//相机位置
    std::vector<Object*> objects_;//场景物体
    glm::vec2 world_size_=glm::vec2(0.0f);//世界大小
};  







#endif