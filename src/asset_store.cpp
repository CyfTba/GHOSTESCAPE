#include "asset_store.h"

void AssetStore::loadTexture(const std::string &file)
{
    SDL_Texture* texture= IMG_LoadTexture(renderer_,file.c_str());
    if(texture==nullptr){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"加载纹理失败:%s\n",SDL_GetError());
        return;
    }
    textures_.emplace(file,texture);

}

void AssetStore::loadSound(const std::string &file)
{
    Mix_Chunk* sound=Mix_LoadWAV(file.c_str());
    if(sound==nullptr){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"加载音效失败:%s\n",SDL_GetError());
        return;
    }
    sounds_.emplace(file,sound);
}

void AssetStore::loadMusic(const std::string &file)
{
    Mix_Music* music=Mix_LoadMUS(file.c_str());
    if(music==nullptr){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"加载音乐失败:%s\n",SDL_GetError());
        return;
    }
    musics_.emplace(file,music);
}

void AssetStore::loadFont(const std::string &file, int font_size)
{
    TTF_Font* font=TTF_OpenFont(file.c_str(),font_size);
    if(font==nullptr){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"加载字体失败:%s\n",SDL_GetError());
        return;
    }
    fonts_.emplace(file+std::to_string(font_size),font);
}

SDL_Texture* AssetStore::getTexture(const std::string &file)
{
    auto it=textures_.find(file);
    //找到了直接返回
    if(it!=textures_.end()){
        return it->second;
    }
    //否则加载
    else{
        loadTexture(file);
        it=textures_.find(file);
        if(it!=textures_.end()){
            return it->second;
        }else{
            return nullptr;
        }
    }
}

Mix_Chunk *AssetStore::getSound(const std::string &file)
{
    auto it=sounds_.find(file);
    //找到了直接返回
    if(it!=sounds_.end()){
        return it->second;
    }
    //否则加载
    else{
        loadSound(file);
        it=sounds_.find(file);
        if(it!=sounds_.end()){
            return it->second;
        }else{
            return nullptr;
        }
    }
}

Mix_Music *AssetStore::getMusic(const std::string &file)
{
    auto it=musics_.find(file);
    //找到了直接返回
    if(it!=musics_.end()){
        return it->second;
    }
    //否则加载
    else{
        loadMusic(file);
        it=musics_.find(file);
        if(it!=musics_.end()){
            return it->second;
        }else{
            return nullptr;
        }
    }
}

TTF_Font *AssetStore::getFont(const std::string &file, int font_size)
{
    auto it=fonts_.find(file+std::to_string(font_size));
    //找到了直接返回
    if(it!=fonts_.end()){
        return it->second;
    }
    //否则加载
    else{
        loadFont(file,font_size);
        it=fonts_.find(file+std::to_string(font_size));
        if(it!=fonts_.end()){
            return it->second;
        }else{
            return nullptr;
        }
    }
}

void AssetStore::clean()
{
    for(auto& pair:textures_){
        if(pair.second!=nullptr){
            SDL_DestroyTexture(pair.second);
            pair.second=nullptr;
        }
    }
    textures_.clear();

    for(auto& pair:sounds_){
        if(pair.second!=nullptr){
            Mix_FreeChunk(pair.second);
            pair.second=nullptr;
        }
    }
    sounds_.clear();

    for(auto& pair:musics_){
        if(pair.second!=nullptr){
            Mix_FreeMusic(pair.second);
            pair.second=nullptr;
        }
    }
    musics_.clear();

    for(auto& pair:fonts_){
        if(pair.second!=nullptr){
            TTF_CloseFont(pair.second);
            pair.second=nullptr;
        }
    }
    fonts_.clear();
}