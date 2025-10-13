#include "sprite.h"

Texture::Texture(const std::string& file)
{
    texture=Game::GetInstance().getAssetStore()->getTexture(file);
    SDL_GetTextureSize(texture,&srcRect.w,&srcRect.h);

    
}

Sprite *Sprite::addSpriteChild(ObjectScreen *parent, const std::string &file, float scale)
{
    auto *sprite = new Sprite();
    sprite->init();
    sprite->setParrent(parent);
    sprite->setTexture(Texture(file));//调用sprite的setTexture方法
    sprite->setScale(scale);
    parent->addChild(sprite);
    return sprite;
}

void Sprite::setTexture(const Texture &texture)
{
    texture_=texture;
    size_=glm::vec2(texture_.srcRect.w,texture_.srcRect.h);
}

void Sprite::render()
{
    if(texture_.texture==nullptr){
        return;
    }
    auto pos=parrent_->getRenderPosition()+offset_;//附属物的渲染位置=主物体的渲染位置+偏移
    Game::GetInstance().renderTexture(texture_,pos,size_);
}
