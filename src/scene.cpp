#include "scene.h"

void Scene::setCameraPosition(const glm::vec2 &pos)
{   
    camera_position_=pos;
    camera_position_=glm::clamp(camera_position_,glm::vec2(-30.0f),world_size_-game_.GetScreenSize()+glm::vec2(30.0f));//限制相机位置在世界范围内
}