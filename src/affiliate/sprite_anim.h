#ifndef SPRITE_ANIM_H
#define SPRITE_ANIM_H
#include "sprite.h"

class SpriteAnim:public Sprite{
private:
    int current_frame_=0;//当前帧
    int fps_=10;//每秒帧数
    int total_frames_=0;//总帧数
    float frame_timer_=0.0f;//帧计时器,用于计算何时切换到下一帧

public:

    virtual void update(float dt)override;

    int getCurrentFrame()const{return current_frame_;}
    void setCurrentFrame(int frame){current_frame_=frame;}
    int getTotalFrames()const{return total_frames_;}
    void setTotalFrames(int total){total_frames_=total;}
    int getFPS()const{return fps_;}
    void setFPS(int fps){fps_=fps;}

    void setTexture(const Texture& texture)override;

    static SpriteAnim* addSpriteAnimChild(ObjectScreen* parent,const std::string& file,float scale);
};

#endif