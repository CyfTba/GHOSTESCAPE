#ifndef GAME_H
#define GAME_H
#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"
#include "SDL3_mixer/SDL_mixer.h"
#include "SDL3_ttf/SDL_ttf.h"
#include "glm/glm.hpp"
#include <string>
#include "asset_store.h"
class Scene;
//单例模式
class Game{
private:
    glm::vec2 screen_size_=glm::vec2(0);
    SDL_Window* window_=nullptr;//窗口
    SDL_Renderer*renderer_=nullptr;//渲染器
    bool is_running_=true;
    Uint64 FPS_=60;
    Uint64 frame_delay_=0;//帧延迟,单位ns
    float dt_=0.0f;//帧间隔,单位s,保证速度不受帧率影响
    Scene* current_scene_=nullptr;
    //私有的构造函数
    Game(){};
    //禁用拷贝构造和赋值操作符
    Game(const Game&)=delete;
    Game& operator=(const Game&)=delete;
    AssetStore* asset_store_=nullptr;//资源管理器
public:
    static Game& GetInstance(){
        static Game instance;
        return instance;
    }

    void run();//运行游戏，执行主循环
    void init(std::string title, int width, int height);//初始化游戏
    void handleEvents();//事件处理
    void updata(float dt);//更新数据
    void render();//渲染游戏
    void clean();//清理
    Scene* getCurrentScene()const{return current_scene_;}//获取当前场景
    void drawGrid(const glm::vec2& top_left,const glm::vec2& botton_right,float grid_width,SDL_FColor fcolor);//绘制网格
    glm::vec2 GetScreenSize()const{return screen_size_;}//获取屏幕尺寸
    void drawBoundary(const glm::vec2& top_left,const glm::vec2& botton_right,float boundary_width,SDL_FColor fcolor);//绘制边界
    AssetStore* getAssetStore()const{return asset_store_;}//获取资源管理器

};

#endif