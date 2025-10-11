#ifndef OBJECT_H
#define OBJECT_H
#include "game.h"
#include <vector>
#include <algorithm>
#include "defs.h"
class Object{
public:
    Object()=default;
    virtual ~Object()=default;
    virtual void init();
    virtual void handleEvents(SDL_Event& event);
    virtual void update(float dt);
    virtual void render();
    virtual void clean();
    virtual void addChild(Object* child){
        if(child){
            children_.push_back(child);
        }
    }

    virtual void removeChild(Object* child){
        // auto it=std::find(children_.begin(),children_.end(),child);
        // if(it!=children_.end()){
        //     children_.erase(it);
        // }
        children_.erase(std::remove(children_.begin(),children_.end(),child),children_.end());
    }

    ObjectType getType()const{return type_;}
    void setType(ObjectType type){type_=type;}

protected:
    Game& game_=Game::GetInstance();
    std::vector<Object*> children_;//子对象
    ObjectType type_=ObjectType::NONE;//对象类型
};



#endif