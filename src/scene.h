#ifndef SCENE_H
#define SCENE_H

#include"object.h"
#include "glm/glm.hpp"
#include <vector>
#include "object_world.h"
#include "object_screen.h"
class Scene:public Object{
public:
    Scene()=default;
    virtual ~Scene()=default;
    virtual void init()override{};
    virtual void handleEvents(SDL_Event& event)override;
    virtual void update(float dt)override;
    virtual void render()override;
    virtual void clean()override;

    glm::vec2 WorldToScreen(const glm::vec2& world_pos)const{return world_pos - camera_position_;}//世界坐标转屏幕坐标
    glm::vec2 ScreenToWorld(const glm::vec2& screen_pos)const{return screen_pos + camera_position_;}//屏幕坐标转世界坐标 
    glm::vec2 getCameraPosition()const{return camera_position_;}
    void setCameraPosition(const glm::vec2& pos);
    glm::vec2 getWorldSize()const{return world_size_;}
    void setWorldSize(const glm::vec2& size){world_size_=size;}
    virtual void addChild(Object* child)override;
    virtual void removeChild(Object* child)override;
protected:
    glm::vec2 camera_position_=glm::vec2(0);//相机位置
    glm::vec2 world_size_=glm::vec2(0.0f);//世界大小
    //场景中的对象分为三类，普通对象、世界对象、屏幕对象,分别存储在不同的容器中,作用：可以控制渲染顺序和更新顺序和事件处理顺序和分类管理
    std::vector<ObjectWorld*> children_world_;//场景中的对象
    std::vector<ObjectScreen*> children_screen_;//UI对象
};  







#endif