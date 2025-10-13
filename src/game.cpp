#include "game.h"
#include "scene_main.h"
#include "object_screen.h"
#include "object_world.h"
#include "actor.h"
#include "./affiliate/sprite.h"
void Game::run(){
    while(is_running_){
        auto start=SDL_GetTicksNS();//获取当前时间
        handleEvents();
        updata(dt_);
        render();
        auto end=SDL_GetTicksNS();
        auto elapsed=end-start;
        if(elapsed<frame_delay_){
            SDL_DelayNS(frame_delay_-elapsed);
            dt_=frame_delay_/1.0e9;
        }
        else{
            dt_=elapsed/1.0e9;
        }
        //SDL_Log("Frame Time: %f ms, FPS: %f\n",dt_*1000.0f,1.0f/dt_);
    }
}
void Game::init(std::string title, int width, int height){
    screen_size_=glm::vec2(width,height);
    //初始化SDL3
    if(!SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO)){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"SDL初始化失败:%s\n",SDL_GetError());
    }
    //SDL3_Mixer初始化
    if(Mix_Init(MIX_INIT_MP3|MIX_INIT_OGG)!=(MIX_INIT_MP3|MIX_INIT_OGG)){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"SDL_Mixer初始化失败:%s\n",SDL_GetError());
    }

    Mix_AllocateChannels(16);//分配16个音频通道
    Mix_VolumeMusic(MIX_MAX_VOLUME/4);//设置音频音量
    Mix_Volume(-1,MIX_MAX_VOLUME/4);//设置音效音量

    //SDL3_TTF初始化
    if(!TTF_Init()){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"SDL_TTF初始化失败:%s\n",SDL_GetError());
    }
    //创建窗口和渲染器
    SDL_CreateWindowAndRenderer(title.c_str(),width,height,SDL_WINDOW_RESIZABLE,&window_,&renderer_);
    if (!window_ || !renderer_){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "创建窗口或渲染器失败: %s\n", SDL_GetError());
    }
    SDL_SetRenderLogicalPresentation(renderer_,width,height,SDL_LOGICAL_PRESENTATION_LETTERBOX);//设置逻辑渲染
    frame_delay_=1000000000/FPS_;

    asset_store_=new AssetStore(renderer_);//创建资源管理器

    //创建场景
    current_scene_=new Scene_Main();
    current_scene_->init();

}
void Game::handleEvents(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch (event.type)
        {
            //为退出事件
        case SDL_EVENT_QUIT:
            is_running_=false;
            break;
        //否则当前场景处理事件
        default:
            current_scene_->handleEvents(event);
            break;
        }
    }
}
void Game::updata(float dt){
    current_scene_->update(dt);
}
void Game::render(){
    SDL_SetRenderDrawColor(renderer_,0,0,0,255);
    SDL_RenderClear(renderer_);//用设置的颜色清除渲染
    current_scene_->render();
    SDL_RenderPresent(renderer_);
}
void Game::clean(){
    if(current_scene_!=nullptr){
        current_scene_->clean();
        delete current_scene_;
    }

    if(asset_store_!=nullptr){
        asset_store_->clean();
        delete asset_store_;
    }

    if(renderer_!=nullptr){
        SDL_DestroyRenderer(renderer_);
    }
    if(window_!=nullptr){
        SDL_DestroyWindow(window_);
    }
    Mix_CloseAudio();
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();


}

void Game::drawGrid(const glm::vec2 &top_left, const glm::vec2 &botton_right, float grid_width, SDL_FColor fcolor)
{
    SDL_SetRenderDrawColorFloat(renderer_,fcolor.r,fcolor.g,fcolor.b,fcolor.a);
    for(float x=top_left.x;x<=botton_right.x;x+=grid_width){
        SDL_RenderLine(renderer_,x,top_left.y,x,botton_right.y);//竖线
    }
    for(float y=top_left.y;y<=botton_right.y;y+=grid_width){
        SDL_RenderLine(renderer_,top_left.x,y,botton_right.x,y);//横线
    }
    SDL_SetRenderDrawColorFloat(renderer_,0,0,0,1);//恢复默认颜色
}


void Game::drawBoundary(const glm::vec2 &top_left, const glm::vec2 &botton_right, float boundary_width, SDL_FColor fcolor)
{
    SDL_SetRenderDrawColorFloat(renderer_,fcolor.r,fcolor.g,fcolor.b,fcolor.a);
    for(float i=0;i<boundary_width;i++){
        SDL_FRect rect={
            top_left.x-i,
            top_left.y-i,
            botton_right.x-top_left.x+2*i,//宽
            botton_right.y-top_left.y+2*i//高
        };
        SDL_RenderRect(renderer_,&rect);
    }
    SDL_SetRenderDrawColorFloat(renderer_,0,0,0,1);//恢复默认颜色
}

void Game::renderTexture(const Texture &texture, const glm::vec2 &position, const glm::vec2 &size)
{
    SDL_FRect destRect={position.x,position.y,size.x,size.y};//目标矩形,渲染到屏幕的位置和大小
    SDL_RenderTextureRotated(renderer_,texture.texture,&texture.srcRect,&destRect,texture.angle,nullptr,texture.is_flip?SDL_FLIP_HORIZONTAL:SDL_FLIP_NONE);
}
