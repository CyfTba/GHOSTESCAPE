#ifndef SPRITE_H
#define SPRITE_H

#include "../object_affiliate.h"

struct Texture
{
    SDL_Texture* texture=nullptr;
    SDL_FRect srcRect={0,0,0,0};//纹理源矩形，用于裁剪,默认整个纹理大小，x,y为原点位置，w,h为宽高
    float angle=0.0f;
    bool is_flip=false;//是否水平翻转
    Texture(const std::string& file);
    Texture()=default;
};

class Sprite:public ObjectAffiliate{
protected:
    Texture texture_;//纹理

public:
    static Sprite* addSpriteChild(ObjectScreen* parent,const std::string& file,float scale=1.0f);
    Texture getTexture()const {return texture_;}
    virtual void setTexture(const Texture& texture);//设置纹理和大小
    virtual void render()override;//渲染
    Sprite()=default;
    void setScale(float scale){
        size_*=scale;
    }
};




#endif