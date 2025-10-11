#include "player.h"
#include "scene.h"
#include "affiliate/sprite.h"
void Player::init()
{
    Actor::init();
    auto sprite=new Sprite();
    sprite->setTexture(Texture("assets/sprite/ghost-idle.png"));
    sprite->setParrent(this);
    addChild(sprite);
}

void Player::handleEvents(SDL_Event &event)
{
    Actor::handleEvents(event);
}

void Player::update(float dt)
{   
    Actor::update(dt);
    keyboardControl();
    move(dt);
    syncCameraPosition();
}

void Player::render()
{   
    Actor::render();
}

void Player::clean()
{
    Actor::clean();
}

void Player::keyboardControl()
{   
    move_vector_=glm::vec2(0);
    auto state=SDL_GetKeyboardState(NULL);
    if(state[SDL_SCANCODE_W]){
        move_vector_.y=-1;
        //velocity_.y=-max_speed_;
    }
    if(state[SDL_SCANCODE_S]){ 
        move_vector_.y=1;
        //velocity_.y=max_speed_;
    }
    if(state[SDL_SCANCODE_A]){
        move_vector_.x=-1;
        //velocity_.x=-max_speed_;
    }
    if(state[SDL_SCANCODE_D]){
        move_vector_.x=1;
        //velocity_.x=max_speed_;
    }
}

void Player::move(float dt)
{   
    //向四周角移动会比普通方向快，应当向量归一化
    // 加入移动衰减，只有有输入时才更新速度，否则速度逐渐减小
    if(glm::length(move_vector_)>0) {
        move_vector_ = glm::normalize(move_vector_);
        velocity_ = move_vector_ * max_speed_;
    } else {
        velocity_ *= 0.9f; // 无输入时速度衰减
    }
    setPosition(position_ + velocity_ * dt);
    SDL_Log("dt: %f, position: (%f, %f), velocity: (%f, %f,%f,%f)", dt, position_.x, position_.y, velocity_.x, velocity_.y,move_vector_.x,move_vector_.y);

    //待优化：限制范围应当考虑物体大小😉
    position_=glm::clamp(position_,glm::vec2(0.0f),game_.getCurrentScene()->getWorldSize());//限制在世界范围内,clamp函数用于将值限制在指定范围内
}

void Player::syncCameraPosition()
{
    game_.getCurrentScene()->setCameraPosition(position_-game_.GetScreenSize()/2.0f);
}
