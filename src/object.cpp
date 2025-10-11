#include "object.h"

void Object::render(){
    for(auto& child:children_){
        if(child){
            child->render();
        }
    }
}

void Object::handleEvents(SDL_Event& event){
    for(auto& child:children_){
        if(child){
            child->handleEvents(event);
        }
    }
}

void Object::update(float dt){
    for(auto& child:children_){
        if(child){
            child->update(dt);
        }
    }
}

void Object::clean(){
    for(auto& child:children_){
        if(child){
            child->clean();
            delete child;
        }
    }
    children_.clear();
}

void Object::init(){
    type_=ObjectType::NONE;
}