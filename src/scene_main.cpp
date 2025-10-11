#include "scene_main.h"

void Scene_Main::init(){
    world_size_=game_.GetScreenSize()*3.0f;//世界大小为屏幕的3倍
    player_=new Player();
    player_->init();
    player_->setPosition(world_size_/2.0f);//设置玩家初始位置在世界中心
    camera_position_=world_size_/2.0f - game_.GetScreenSize()/2.0f;//初始相机位置在世界中心
    addChild(player_);//添加玩家到场景
}

void Scene_Main::handleEvents(SDL_Event& event){

    Scene::handleEvents(event);
 
}

void Scene_Main::update(float dt)
{
    Scene::update(dt);
 
}

void Scene_Main::render()
{
    drawBackground();
    Scene::render();
    
}

void Scene_Main::clean()
{
    Scene::clean();

}

void Scene_Main::drawBackground()
{   
    //实际是渲染将背景网格向相机反方向移动
    auto start=0.0f-camera_position_;
    auto end=world_size_-camera_position_;
    game_.drawGrid(start,end,80.0f,{0.5,0.5,0.5,1.0});//物体在窗口的坐标=物体在世界的坐标-相机位置
    game_.drawBoundary(start,end,5.0f,{1.0,1.0,1.0,1.0});//绘制世界边界
}
