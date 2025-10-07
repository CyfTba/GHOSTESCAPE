#include "player.h"
#include "scene.h"
void Player::init()
{
}

void Player::handleEvents(SDL_Event &event)
{
}

void Player::update(float dt)
{   
    velocity_*=0.9f;//速度衰减
    keyboardControl();
    move(dt);
    syncCameraPosition();
}

void Player::render()
{
    game_.drawBoundary(render_position_,render_position_+glm::vec2(20.0f),5,{1.0,0.0,0.0,1.0});
}

void Player::clean()
{
}

void Player::keyboardControl()
{   
  
    auto state=SDL_GetKeyboardState(NULL);
    if(state[SDL_SCANCODE_W]){
        velocity_.y=-max_speed_;
    }
    if(state[SDL_SCANCODE_S]){ 
        velocity_.y=max_speed_;
    }
    if(state[SDL_SCANCODE_A]){
        velocity_.x=-max_speed_;
    }
    if(state[SDL_SCANCODE_D]){
        velocity_.x=max_speed_;
    }
}

void Player::move(float dt)
{   
    //待优化：向四周角移动会比普通方向快，应当向量归一化
    setPosition(position_+velocity_*dt);
    SDL_Log("dt: %f, position: (%f, %f), velocity: (%f, %f)", dt, position_.x, position_.y, velocity_.x, velocity_.y);

    //待优化：限制范围应当考虑物体大小😉
    position_=glm::clamp(position_,glm::vec2(0.0f),game_.getCurrentScene()->getWorldSize());//限制在世界范围内,clamp函数用于将值限制在指定范围内
}

void Player::syncCameraPosition()
{
    game_.getCurrentScene()->setCameraPosition(position_-game_.GetScreenSize()/2.0f);
}
