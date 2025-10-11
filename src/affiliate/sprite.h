#ifndef SPRITE_H
#define SPRITE_H

#include "../object_affiliate.h"

struct Texture
{
    SDL_Texture* texture=nullptr;
    SDL_FRect srcRect={0,0,0,0};//纹理源矩形
    float angle=0.0f;
    bool is_flip=false;//是否水平翻转
    Texture(const std::string& file);
    Texture()=default;
};

class Sprite:public ObjectAffiliate{
protected:
    Texture texture_;//纹理

public:
    Texture getTexture()const {return texture_;}
    void setTexture(const Texture& texture);//设置纹理和大小
    virtual void render()override;//渲染
    Sprite()=default;
};




#endif