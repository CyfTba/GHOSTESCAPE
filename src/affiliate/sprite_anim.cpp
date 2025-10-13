#include "sprite_anim.h"

void SpriteAnim::update(float dt)
{
    frame_timer_+=dt;//增加计时
    //计时器超过每帧时间则切换到下一帧
    if(frame_timer_>1.0f/fps_){
        frame_timer_=0.0f;
        //切换到下一帧，循环播放
        current_frame_=(current_frame_+1)%total_frames_;
        //更新纹理的srcRect以显示当前帧
        if(texture_.texture){
            texture_.srcRect.x=current_frame_*texture_.srcRect.w;//更新裁剪矩形的x位置
        }
    }
}

void SpriteAnim::setTexture(const Texture &texture)
{
    texture_=texture;
    total_frames_=texture.srcRect.w/texture.srcRect.h;
    texture_.srcRect.w=texture_.srcRect.h;//假设每帧是正方形
    size_=glm::vec2(texture_.srcRect.w,texture_.srcRect.h);
}

SpriteAnim *SpriteAnim::addSpriteAnimChild(ObjectScreen *parent, const std::string &file, float scale)
{
    auto *sprite_anim = new SpriteAnim();
    sprite_anim->init();
    sprite_anim->setParrent(parent);
    sprite_anim->setTexture(Texture(file));
    sprite_anim->setScale(scale);
    parent->addChild(sprite_anim);
    return sprite_anim;
}
