#ifndef ASSET_STORE_H
#define ASSET_STORE_H

#include <unordered_map>
#include <string>
#include "SDL3/SDL.h"
#include "SDL3_mixer/SDL_mixer.h"
#include "SDL3_ttf/SDL_ttf.h"
#include "SDL3_image/SDL_image.h"
class AssetStore {
    std::unordered_map<std::string,SDL_Texture*> textures_;
    std::unordered_map<std::string,Mix_Chunk*> sounds_;
    std::unordered_map<std::string,Mix_Music*> musics_;
    std::unordered_map<std::string,TTF_Font*> fonts_;
    SDL_Renderer* renderer_=nullptr;
public:
    AssetStore(SDL_Renderer* renderer){renderer_=renderer;};
    ~AssetStore()=default;
    //读取
    SDL_Texture* getTexture(const std::string& file);
    Mix_Chunk* getSound(const std::string& file);
    Mix_Music* getMusic(const std::string& file);
    TTF_Font* getFont(const std::string& file,int font_size);
    //载入
    void loadTexture(const std::string& file);
    void loadSound(const std::string& file);
    void loadMusic(const std::string& file);
    void loadFont(const std::string& file,int font_size);

    //清理
    void clean();


};










#endif