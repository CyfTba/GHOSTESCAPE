#include "scene.h"

void Scene::setCameraPosition(const glm::vec2 &pos)
{   
    camera_position_=pos;
    camera_position_=glm::clamp(camera_position_,glm::vec2(-30.0f),world_size_-game_.GetScreenSize()+glm::vec2(30.0f));//限制相机位置在世界范围内
}

void Scene::addChild(Object *child)
{
    switch (child->getType())
    {
    case ObjectType::OBJECT_SCREEN:
        children_screen_.push_back(dynamic_cast<ObjectScreen*>(child));
        break;
    case ObjectType::OBJECT_WORLD:
        children_world_.push_back(dynamic_cast<ObjectWorld*>(child));
        break;
    default:
        children_.push_back(child);
        break;
    }
}

void Scene::removeChild(Object *child)
{
    switch (child->getType())
    {
    case ObjectType::OBJECT_SCREEN:
        children_screen_.erase(std::remove(children_screen_.begin(),children_screen_.end(),dynamic_cast<ObjectScreen*>(child)),children_screen_.end());
        break;
    case ObjectType::OBJECT_WORLD:
        children_world_.erase(std::remove(children_world_.begin(),children_world_.end(),dynamic_cast<ObjectWorld*>(child)),children_world_.end());
        break;
    default:
        children_.erase(std::remove(children_.begin(),children_.end(),child),children_.end());
        break;
    }
}

void Scene::render()
{
    Object::render();
    //渲染场景中的世界对象
    for(auto& child:children_world_){
        if(child){
            child->render();
        }
    }
    //渲染场景中的屏幕对象
    for(auto& child:children_screen_){
        if(child){
            child->render();
        }
    }
}

void Scene::handleEvents(SDL_Event &event)
{
    Object::handleEvents(event);
    //处理场景中的屏幕对象事件 
    for(auto& child:children_screen_){
        if(child){
            child->handleEvents(event);
        }
    }
    //处理场景中的世界对象事件
    for(auto& child:children_world_){
        if(child){
            child->handleEvents(event);
        }
    }

}

void Scene::update(float dt)
{
    Object::update(dt);
    //更新场景中的世界对象
    for(auto& child:children_world_){
        if(child){
            child->update(dt);
        }
    }
    //更新场景中的屏幕对象
    for(auto& child:children_screen_){
        if(child){
            child->update(dt);
        }
    }
}

void Scene::clean()
{
    Object::clean();
    //清理场景中的世界对象
    for(auto& child:children_world_){
        if(child){
            child->clean();
            delete child;
        }
    }
    children_world_.clear();
    //清理场景中的屏幕对象
    for(auto& child:children_screen_){
        if(child){
            child->clean();
            delete child;
        }
    }
    children_screen_.clear();
}

